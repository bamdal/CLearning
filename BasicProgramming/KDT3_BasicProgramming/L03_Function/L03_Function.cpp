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

	namespace TEST	// namespace안에 namespace를 넣을 수 있다
	{
		int A;
		int B;
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
		
		int A = 100;
		int B = 500;
		// Call by Value (값의 의한 전달)
		int iRet = MyTestFunc3(A, B); // MyTestFunc3 호출 / Argument(인자)로 100,500로 전달
		std::cout << "Add iRet : " << iRet << std::endl;

		iRet = MyMultiplyFunc(50, 2);
		std::cout << "Mul iRet : " << iRet << std::endl;

	}
#pragma endregion

#pragma region L03_Function / namespace
	{
		Print();		// NewJeans namespace로 인식
		BTS::Print();
		// namespace를 사용하기 전까진 컴파일 에러 NewJeans껀지 BTS껀지 모름.
		// namespace를 둘 다 사용해도 어디껀지 몰라서 컴파일 에러 => :: 연산자 사용해서 그룹 명시
		SamplePrint();   

		Sample::TEST::A;	// namespace안에 namespace를 넣을 수 있다
		TEST::B; // using namespace를 했으니 Sample생략 가능
	}
#pragma endregion

#pragma region L03_Function / 변수의 범위(Scope)
	{
		int iLocal1 = 100;
		cout << "지역변수 iLocal1 = " << iLocal1 << endl;
		
		{
			int iLocal2 = 200;
			cout << "지역변수 iLocal1 = " << iLocal1 << endl;
			cout << "지역변수 iLocal2 = " << iLocal2 << endl;
		}

		// cout << "지역변수 iLocal2 = " << iLocal2 << endl;
		// {} 안에 선언된 지역변수는 외부에서 접근 불가

		MyScopeTestFunc();
		cout << "main에서 사용 : 전역변수 iGlobalVal = " << iGlobalVal << endl;

		int iGlobalVal = 123;
		cout << "main에서 사용 : 지역변수 iGlobalVal = " << iGlobalVal << endl;
		// 전역과 로컬에 동일 이름의 변수가 있을 시 cout 결과는 로컬을 출력 => 로컬변수가 우선권이 높음.
		// 디버깅시 각 iGlobalVal이 비정상 값으로 노출될 수 있다. => 이름 중복은 반드시 피해야 한다.
		cout << "불가피할 경우 ::iGlobalVal =" << ::iGlobalVal << endl;
	}
#pragma endregion

#pragma region L03_Function / 함수의 디폴트 인자와 Overloading
	{
		int iRet = MyAddFunc(100,200);
		cout << "MyAddFunc의 인자 2개 모두 넣기 (100,200) : " << iRet << endl;
		iRet = MyAddFunc(100);
		cout << "MyAddFunc의 인자 1개 넣기 (100) : " << iRet << endl;

		cout << "Overloading 1 : " << MyAddFuncOver(10) << endl;
		cout << "Overloading 2 : " << MyAddFuncOver(10,20) << endl;
		cout << "Overloading 2 : " << MyAddFuncOver('A', 10, 20) << endl;
	}
#pragma endregion

}
