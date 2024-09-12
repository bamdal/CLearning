// L21_FileIO.cpp : 파일 입출력
#include <iostream>
#include <fstream>
#include <format>
#include "IniParser/inicpp.h"

using namespace std;

/// <summary>
/// C++ File Write (Text) / output file stream : ofstream
/// </summary>
/// <param name="_OS"></param>
void TestFileWrite(std::ofstream& _OS)
{
	string String = "한글입력 Hello File!\n HEllo~~~\n";
	const size_t WriteSize = String.size();


	_OS.write((const char*)&WriteSize, sizeof(size_t));	// 1) 문자열의 사이즈 저장
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

		int ii = 0;

	}
#pragma endregion

}

