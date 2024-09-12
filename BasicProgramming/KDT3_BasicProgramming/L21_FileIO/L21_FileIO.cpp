// L21_FileIO.cpp : 파일 입출력
#include <iostream>
#include <fstream>
#include <format>
#include "IniParser/inicpp.h"

#include "../../../rapidjson/include/rapidjson/document.h"
#include "../../../rapidjson/include/rapidjson/writer.h"
#include "../../../rapidjson/include/rapidjson/stringbuffer.h"


using namespace std;

/// <summary>
/// C++ File Write (Text) / output file stream : ofstream
/// </summary>
/// <param name="_OS"></param>
void TestFileWrite(std::ofstream& _OS)
{
	string String = "한글입력 Hello File!\n HEllo~~~\n";
	const size_t WriteSize = String.size();


	_OS.write((const char*)&WriteSize, sizeof(size_t));		// 1) 문자열의 사이즈 저장
	_OS.write(String.c_str(), String.size());				// 2) 문자열 저장


	int Int = 65;
	_OS.write(reinterpret_cast<char*>(&Int), sizeof(int));	// 3) 정수형 4Byte를 캐릭터로 (재해석) 저장
	_OS.close();
}

/// <summary>
/// C++ File Read (Text) / input file stream : ifstream
/// </summary>
/// <param name="_IS"></param>
/// <param name="binary">바이너리모드 = true, 텍스트모드 = false</param>
void TestFileRead(std::ifstream& _IS, bool binary = false)
{
	size_t ReadSize = 0;
	_IS.read(reinterpret_cast<char*>(&ReadSize), sizeof(size_t));	// 1) 문자열의 사이즈 읽기
	string String;
	String.resize(ReadSize);
	_IS.read(String.data(), String.size());							// 2) 문자열 읽기

	int Int = 0;
	_IS.read(reinterpret_cast<char*>(&Int), sizeof(int));			// 3) 정수형 4Byte를 읽기

	_IS.close();	// 파일 닫기

	string strType = "<Binary>\n";
	if (!binary)
	{
		strType = "<Text>\n";
	}
	if (!String.empty())
	{
		cout << format("{} File Read size : [{}]\n {} {}",strType.c_str(),ReadSize,String.c_str(),Int) << endl;
	}
}

int main()
{
#pragma region C++ File Input/Output system
	// [텍스트 모드]
	// 기본적으로 파일을 텍스트 모드로 열면, OS에 따라 줄바꿈 문자가 추가
	// ex) Window에서 엔터(\n)를 텍스트 파일에 치면 "\r\n"으로 변환
	// 텍스트 모드에서는 파일의 끝을 나타내는 문자가 있을 때 읽기가 중단될 수 있다.
	// [바이너리 모드]
	// 일단 데이터의 변환없이 그대로 읽고 써진다.
	// 줄바꿈 문자나 파일의 끝을 나타내는 문자가 변환되지 않는다.
	// ex) 게임의 리소스(스프라이트, 모델, 이미지, 음악파일...) 등 처리

	// C++ File Write (Text) / output file stream : ofstream
	{
		std::ofstream OutputStream = std::ofstream("Test.txt", std::ios::out);
		if (OutputStream.is_open())
		{
			TestFileWrite(OutputStream);
		}

		//C++ File Read (Text) / input file stream : ifstream
		{
			std:ifstream inputStream = std::ifstream("Test.txt", std::ios::in);
			if (inputStream.is_open())
			{
				TestFileRead(inputStream);

			}
		}
	}

	// File Write (Binary)
	{
		std::ofstream OutputStream = std::ofstream("TestBinary.txt", std::ios::out | std::ios::binary);	// 바이너리 플래그 추가
		if (OutputStream.is_open())
		{
			TestFileWrite(OutputStream);
		}
	}
	// File Read (Binary)
	{
		std::ifstream InputStream = std::ifstream("TestBinary.txt", std::ios::in | std::ios::binary);
		if (InputStream.is_open())
		{
			TestFileRead(InputStream, true);
		}
	}
#pragma endregion
#pragma region INI 파일
	{
		// inicpp.h 깃에서 받아서 사용
		ini::IniFile File;	// 내부적으로 map을 사용 (Key : string, Value : map) (Key : stiring, Value : iniField)
		// [세션의 이름][필드에 들어갈 항목] = value값 
		File["A Section"]["FieldKey1"] = 0;
		File["A Section"]["FieldKey2"] = 122;
		File["A Section"]["FieldKey3"] = 1123;

		File["B Section"]["FieldKey1"] = 2223;
		File["B Section"]["FieldKey3"] = 22235;
		File["B Section"]["FieldKey2"] = 22234;

		File["C Graphics"]["Width"] = 2560;
		File["C Graphics"]["Height"] = 1440;
		File["C Graphics"]["Test"] = "Something_value";
		File["C Graphics"]["Test2"] = "Something value";

		File.save("IniFile.ini");

	}

	{
		ini::IniFile File("IniFile.ini");
		//File.load("IniFile.ini");
		ini::IniField& Field = File["C Graphics"]["Test"];
		std::string String = Field.as<std::string>();
		std::string String2 = File["C Graphics"]["Test2"].as<std::string>();


		int intVar = File["B Section"]["FieldKey1"].as<int>();


		std::vector<int> Result;
		for (int i = 0; i < 3; i++)
		{
			const std::string KeyName = "FieldKey" + std::to_string(i + 1);
			int value = File["A Section"][KeyName].as<int>();
			Result.push_back(value);
		}
		int Width = File["C Graphics"]["Width"].as<int>();
		int Height = File["C Graphics"]["Height"].as<int>();

		ini::IniSection Section = File["B Section"];
		for (std::pair<const std::string, ini::IniField> it : Section)
		{
			cout << format("Key : {}, Value : {}\n", it.first, it.second.as<std::string>());
		}
	}
#pragma endregion

#pragma region json 파일
	{
		struct FPlayer
		{
		private:
			string Name;
			int Level = 0;
			int Exp = 0;

		public:
			FPlayer() = default;	// 컴파일러가 만들어준 default constructor사용
			FPlayer& operator = (const FPlayer& rhs) = default;	// 컴파일러가 만들어준 대입 연산자 사용
			FPlayer(const FPlayer&) = default;					// 컴파일러가 만들어준 default copy constructor 사용
			FPlayer(string_view InName, const int InLevel, const int InExp) noexcept	// 예외를 방출하지 않음(https://lakanto.tistory.com/35)
				:Name(InName), Level(InLevel), Exp(InExp)
			{

			}
			virtual ~FPlayer() = default;	// 컴파일러가 만들어준 default constructor사용

			void PrintPlayerInfo()
			{
				cout << format("Name : {}, Level : {}, Exp : {}", Name, Level, Exp);
			}

			void Save(rapidjson::Value& InOutValue, rapidjson::Document::AllocatorType& InAllocator)
			{
				if (Name.empty())
				{
					_ASSERT(false);
				}
				rapidjson::Value PlayerNameString(rapidjson::kStringType);
				PlayerNameString.SetString(Name.c_str(),InAllocator);
				
				InOutValue.AddMember("PlayerName", PlayerNameString, InAllocator);
				InOutValue.AddMember("PlayerLevel", Level, InAllocator);
				InOutValue.AddMember("PlayerExp", Exp, InAllocator);

			}

			void Load(const rapidjson::Value& InValue)
			{
				if (InValue.HasMember("PlayerName"))
				{
					const char* String = InValue["PlayerName"].GetString();
					Name = String;
				}
				else
				{
					_ASSERT(false);
					Name = "DefaultName";
				}

				if (InValue.HasMember("Level"))
				{
					Level = InValue["Level"].GetInt();
				}

				if (InValue.HasMember("Exp"))
				{
					Exp = InValue["Exp"].GetInt();
				}
			}
		};

		using uint = unsigned int;
		// constexpr 는 컴파일단계에서 설정 const는 나중에라도 먼저 들어온 값으로 고정
		constexpr uint PlayerNumber = 3;
		{
			vector<FPlayer> Players;
			Players.reserve(PlayerNumber);

			for (uint i = 0; i < PlayerNumber; i++)
			{
				string Name = "Player" + to_string(i);
				Players.emplace_back(Name, i, i + 100);
			}

			rapidjson::Document Doc(rapidjson::kObjectType);
			rapidjson::Value Array(rapidjson::kArrayType);
			for (FPlayer& it : Players)
			{
				rapidjson::Value PlayerValue(rapidjson::kObjectType);
				it.Save(PlayerValue, Doc.GetAllocator());

				Array.PushBack(PlayerValue, Doc.GetAllocator());
			}

			Doc.AddMember("PlayerInfo", Array, Doc.GetAllocator());
			
			rapidjson::StringBuffer Buffer;
			rapidjson::Writer<rapidjson::StringBuffer> Writer(Buffer);
			Doc.Accept(Writer);
			string Json(Buffer.GetString(),Buffer.GetSize());



			std::ofstream File("TestJson.json");
			File << Json;
		}
		// Load
		{
			std::vector<FPlayer> Players;
			std::ifstream File("TestJson.json");
			std::string Json;
			std::string TempLine;
			while (std::getline(File, TempLine))
			{
				Json += TempLine;
			}
			rapidjson::Document Doc(rapidjson::kObjectType);
			Doc.Parse(Json.data());

			bool bPlayerInfo = Doc.HasMember("PlayerInfo");
			if (bPlayerInfo)
			{
				rapidjson::Value& Array = Doc["PlayerInfo"];
				if (Array.IsArray())
				{
					const rapidjson::SizeType Size = Array.Size();
					for (rapidjson::SizeType i = 0; i < Size; i++)
					{
						FPlayer NewPlayer;
						rapidjson::Value& Value = Array[i];
						NewPlayer.Load(Value);
						Players.emplace_back(NewPlayer);
					}
				}
			}

			for (auto& it : Players)
			{
				it.PrintPlayerInfo();
			}
		}

	}
#pragma endregion


}

