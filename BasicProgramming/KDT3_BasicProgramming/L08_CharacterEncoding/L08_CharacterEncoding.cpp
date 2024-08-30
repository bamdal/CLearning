#include <Windows.h>
#include <format>
#include <string>
#include <iostream>
using namespace std;

int main()
{
#pragma region L08_CharacterEncoding / C와 C++ 스타일의 문자열 처리 비교
	//C 스타일
	{
		cout << "[C스타일의 문자열 복습]" << endl;
		char szString1[6] = "Hello";		// 문자열 끝에 '\0'이 들어있다
		char szString2[] = "World!";		// 문자열 리터럴
		printf("%s, %s\n", szString1, szString2);

		char cTemp = szString1[0];			// 'H'
		szString1[0] = szString2[0];		// "Wello"
		szString2[0] = cTemp;				// "Horld!"
		printf("%s, %s\n", szString1, szString2);

		char* ptrStr = szString1;
		*(ptrStr) = 'H';					// "Hello"
		printf("%s", ptrStr);
		ptrStr = szString2;
		*ptrStr = 'W';						// "World!"
		printf(" %s\n", ptrStr);

		// 장점 : 가볍고 빠르고 필요한 만큼만 메모리 사용
		// 단점 : 편의 기능이 없다. 복잡한 문자열 조합 시 버그가 발생하기 쉽다
	}

	// C++ 스타일
	{
		cout << "[C++ 스타일의 문자열]" << endl;

		std::string A = "Hello ";
		std::string B = "World!";
		string C = A + B;
		cout << "1) " << C << endl;
		A += B;
		cout << "2) " << A << endl;
		string D = "Hello ";
		D.append(B);
		cout << "3) " << D << endl;

		// 장점 : 편의기능이 내장
		// 단점 : 없음 (사실 C스타일보단 느리고 메모리도 더 쓰겠지만 무시해도 될 수준)
	}

	{
		// C 문자열 리터럴 비교
		const char* A = "Hello";	// Data 영역
		const char B[] = "Hello";	// Stack 영역
		const char* C = "Hello";	// Data 영역		=> A,C는 동일한 주소를 가리킴

		if (A == C)
		{
			cout << &A << ", " << &B << ", " << &C << endl;

		}

		bool bSame = true;
		for (int i = 0; i < 5 ; i++)
		{
			if (A[i] != B[i])
			{
				bSame = false;
				break;
			}
		}

		if (bSame)
		{
			cout << "동일한 문자열 리터럴을 가리키는 포인터는 값과 가리키는 주소가 같다\n";
		}


		// C++ 방식
		const int Result = strcmp(A, B);
		if (Result == 0)	// 같다
		{
			cout << "두 문자열의 다른 부분이 없다\n";
		}

		string AA = "Assort Rock";
		string BB = "Assort Rock";
		if (AA == BB)
		{
			cout << "AA == BB\n";
			
		}
		if (AA._Equal(BB))	// 같으면 true를 반환
		{
			cout << "AA._Equal(BB)\n";
		}

		
	}
#pragma endregion

#pragma region L08_CharacterEncoding / 유니코드
	{
		std::wstring wString1 = L"안녕 Hello!";
		std::wstring wString2 = TEXT("안녕 Hello!");

		if (wString1 == wString2)
		{
			cout << "두 문자열은 같다. TEXT매크로가 string앞에 L을 자동으로 연결해준다" << endl;
			cout << "char의 사이즈 : " << sizeof(char) << ", wchar_t의 사이즈 : " << sizeof(wchar_t) << endl;
		}

		std::wstring wString3 = TEXT("");

		if (wString3.empty())	// 현재 이 문자열이 비어 있다면
		{
			wString3 = TEXT("Hello World!");
			wcout << wString3 << endl;
		}
		if (!wString3.empty())
		{
			size_t Size = wString3.length();
			cout << Size << endl;

			const size_t FindIndex = wString3.find(TEXT("New"));	// 특정 문자열이 포함되어 있는지
			if (FindIndex == std::wstring::npos)	// 포함되어있지 않으면
			{
				const size_t FindIndex = wString3.find(TEXT("Wor"));
				if (FindIndex != std::wstring::npos)	// 포함되어 있으면
				{
					cout << std::format("Wor의 Index = {}", FindIndex) << endl;	// {} 안에 FindIndex가 들어감 
					wString3.replace(FindIndex, 2, TEXT("@#"));	// 해당 인덱스의 문자열 치환
					for (size_t i = 0; i < wString3.length(); i++)
					{
						wcout << wString3[i];
					}
					wcout << endl;
				}
			}
		}

		// 문자열을 다른 자료형으로 변환(중요)
		{
			// 문자열을 정수로
			wstring Number1 = TEXT("20");
			int Number = std::stoi(Number1);
			cout << "wstring 을 int로 변환 : " << Number << endl;

			// 정수를 문자열로
			wstring Number2 = std::to_wstring(1234);	// wchar_t
			wcout << "1) 문자열로 변경된 값 : " << Number2 << endl;
			string Number3 = std::to_string(5678);		// char
			cout << "2) 문자열로 변경된 값 : " << Number3 << endl;

			wstring Float = TEXT("2.35");
			float F = std::stof(Float);
			cout << "3) 실수형으로 변경된 값 : " << F << endl;

			float F2 = 54.6f;
			wstring Float1 = std::to_wstring(F2);
			wcout << "4) 문자열로 변경된 값 : " << Float1 << endl;

			// UTF8
			std::u8string str = u8"A";
			str = u8"한글";
			str = u8"∑";
			std::u8string s = u8"漢子";
			int i = 0;
		}
	}
#pragma endregion

}
