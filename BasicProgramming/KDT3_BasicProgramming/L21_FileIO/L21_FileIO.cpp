// L21_FileIO.cpp : 파일 입출력
#include <iostream>
#include <fstream>
#include <format>

using namespace std;


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
			string String = "Hello  File!\n";
			OutputStream.write(String.c_str(), String.size());
			OutputStream.close();
		}
	}
#pragma endregion

}

