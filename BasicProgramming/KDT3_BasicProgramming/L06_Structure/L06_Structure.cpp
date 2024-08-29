#include "MyCharacter.h"
#include <iostream>
using namespace std;

// 타입 정의
typedef signed char		MyInt8;		// 앞으로 "MyInt8" 자료형은 "signed char" 와 같다.
typedef unsigned char	MyUInt8;
typedef int				MyInt32;	// UE는 int32로 타입정리
typedef long long		MyInt64;	// UE는 int64로 타입정리

enum MY_COLOR
{
	COLOR_RED = 'A',	// 첫번째 원소의 값을 명시하지 않으면 0부터 시작한다.
	COLOR_GREEN,
	COLOR_BULE,
};

enum ETest : MyInt32	// int와 같다
{
	Test_First = 1,
	Test_Second1 = 2,
	Test_Second2 = 2,	// 중복된 값을 정의 할 수는 있다. (조심)
	Test_Third = 100,	// 값의 크기는 MyInt32 안에서 자유롭게 가능함
	Test_What,			// 중간에 값을 명시하지않으면 이전 값에서 +1 시킨다.
};

int main()
{
#pragma region typedef / enum형
	{
		// typedef 예시

		MyInt8 A = 'H';
		cout << "MyInt8 타입 : " << A << endl;
		MyInt32 B = 100, C = -12345;
		cout << "MyInt32 타입 : " << B + C << endl;

		MY_COLOR color = MY_COLOR(COLOR_RED);
		MY_COLOR color2 = MY_COLOR::COLOR_RED;
		switch (color)
		{
		case COLOR_RED:
			cout << "color : " << "RED" << endl;
			break;
		case COLOR_GREEN:
			cout << "color : " << "GREEN" << endl;
			break;
		case COLOR_BULE:
			cout << "color : " << "BULE" << endl;
			break;
		default:
			break;
		}

		switch (color2)
		{
		case COLOR_RED:
			cout << "color : " << "RED" << endl;
			break;
		case COLOR_GREEN:
			cout << "color : " << "GREEN" << endl;
			break;
		case COLOR_BULE:
			cout << "color : " << "BULE" << endl;
			
			break;
		default:
			break;
		}

		ETest test1 = ETest::Test_Second1;
		ETest test2 = ETest::Test_Second2;

		if (test1 == test2)
		{
			cout << "ETest 출력" << endl;
			cout << "Test_What 출력 : " << ETest::Test_What << endl;
			
		}

	}
#pragma endregion

#pragma region 구조체
	{
		MyCharacter Char1;
		Char1.ClassType = ECharClass::Rogue;
		Char1.Level = 5;
		Char1.Exp = 100;

		Char1.PrintInfo();

		MyCharacter Char2;
		Char2.PrintInfo();
	}

	
#pragma endregion

}

