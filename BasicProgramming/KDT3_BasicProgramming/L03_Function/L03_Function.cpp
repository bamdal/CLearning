#include <iostream>
using namespace std;

#include "MyFunction.h"

namespace NewJeans
{
	void Print()
	{
		cout << "NewJeans namespace 사용" << endl;
	}
}

namespace BTS
{
	void Print()
	{
		cout << "BTS namespace 사용" << endl;
	}
}

namespace Sample
{
	void SamplePrint()
	{
		cout << "SamplePrint using namespace 사용" << endl;
	}
}

using namespace NewJeans;
using namespace Sample;

// 함수의 선언 ( 반환값의 자료형 / 함수 이름 / 파라미터 ) => 함수의 프로토타입
void MyTestFunc1();	// MyTestFunc1 함수 선언
void MyTestFunc2();	// 미리 선언을 해둬야 다른 함수들이 정의 전에 사용할 수 있음

void MyTestFunc1()	// MyTestFunc1 함수 정의
{
	//{ } 사이를 함수 Body
	std::cout << "Hello world1\n";
	MyTestFunc2();
}

void MyTestFunc2()
{
	std::cout << "Hello world2\n";
}

/// <summary>
/// 파라메터로 2개의 값을 받아 둘의 합을 리턴함
/// </summary>
/// <param name="param1"></param>
/// <param name="param2"></param>
/// <returns>합계</returns>
int MyTestFunc3(int param1, int param2)
{
	return param1 + param2;
}


int main()
{
#pragma region L03_Function / 함수
	{
		MyTestFunc1();	// MyTestFunc1 함수 호출
		MyTestFunc1();	// 여러번 호출도 가능
		MyTestFunc1();

		int iRet = MyTestFunc3(100, 500); // MyTestFunc3 호출 / Argument(인자)로 100,500로 전달
		std::cout << "Add iRet : " << iRet << std::endl;

		iRet = MyMultiplyFunc(50, 2);
		std::cout << "Mul iRet : " << iRet << std::endl;

	}
#pragma endregion

#pragma region L03_Function / namespace
	{
		Print();		// NewJeans namespace로 인식
		BTS::Print();
		SamplePrint();
	}
#pragma endregion

}
