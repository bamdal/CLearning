#include <iostream>
using namespace std;

int main()
{
#pragma region L07_Pointer_Array / 포인터
	{
		// 스택영역에 변수 초기화
		int iA = -1;
		int* ptrA = &iA;


		cout << "[ 일반 변수의 주소와 값, 포인터 변수의 주소와 값 출력 ]" << endl;
		cout << "int iA의 주소 : " << &iA << " 값 : " << iA << endl;
		cout << "int* ptrA의 주소 : " << &ptrA << " 값 : " << ptrA << endl;
		cout << "int* ptrA의 크기 : " << sizeof(ptrA) << ", (*ptrA)의 크기 : " << sizeof(*ptrA) << endl;
		// 포인터 변수는 가리키는 변수의 크기와 상관없이 무저건 8Byte => 32bit 플랫폼에선 4Byte

		*ptrA = 100;	// 포인터에서 값 변경 ( 역참조 연산자 )
		cout << "int iA의 값 : " << iA << endl;

		// 다중 포인터
		int** ptrB = &ptrA;		// 포인터의 주소를 대임 (2중 포인터)
		int*** ptrC = &ptrB;	// 2중 포인터의 주소를 대입 (3중 포인터) 

		cout << "[ 다중 포인터의 주소와 값 출력]" << iA << endl;
		cout << "int** ptrB의 주소 : " << &ptrB << ", 값 : " << ptrB << endl;
		cout << "int*** ptrC의 주소 : " << &ptrC << ", 값 : " << ptrC << endl;


		**ptrB = 200;	// 2중 포인터에서 값 변경 ( 역참조 연산자 )
		cout << "2중 포인터 int iA의 값 : " << iA << endl;

		***ptrC = 1234;	// 3중 포인터에서 값 변경 ( 역참조 연산자 )
		cout << "3중 포인터 int iA의 값 : " << iA << endl;

	}
#pragma endregion
}

