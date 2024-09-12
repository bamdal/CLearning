// L21_FileIO.cpp : 파일 입출력
#include <iostream>
#include <fstream>
#include <format>

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
		std::ifstream InputStram = std::ifstream("TestBinary.txt", std::ios::in | std::ios::binary);
		if (InputStram.is_open())
		{
			TestFileRead(InputStram, true);
		}
	}
#pragma endregion

}

