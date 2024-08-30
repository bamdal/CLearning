#pragma once

#include <iostream>
using namespace std;
#define MAX_MY_FUNC  4


// call by value
// 입력된 두 값을 서로 바꿔주는 함수
void SwapValue1(int A, int B)
{
	cout << A << ", " << B << endl;
	A += B;
	B = A - B;
	A = A - B;
	cout << A << ", " << B << endl;
}


//void SwapValue1(float A, float B)
//{
//	cout << A << ", " << B << endl;
//	A += B;
//	B = A - B;
//	A = A - B;
//	cout << A << ", " << B << endl;
//}

// call by reference 
void SwapValue2(int* A, int* B)
{
	cout<< "<SwapValue2 호출>" << endl << *A << ", " << *B << endl;
	*A ^= *B;
	*B = *A ^ *B;
	*A = *A ^ *B;
	cout << *A << ", " << *B << endl;
}

// 참조 연산자( 별칭 )
void SwapReference(int &A, int &B)
{
	int iTemp = A;
	A = B;
	B = iTemp;
}

int G = 0;	// 글로벌 변수
void PrintMemortArc(void)
{
	cout << "< 프로그램의 메모리 구조 >" << endl;

	int A = 0;									// 1) 지역변수
	static int B = 0;							// 2) 정적변수
	int* C = (int*)malloc(sizeof(int) * 1000);	// 3) heap 포인터 (C 방식)
	int* D = new int;							// 4) heap 포인터 (C++ 방식 단일)
	int* E = new int[1000];						// 5) heap 포인터 (C++ 방식 배열)
	void(*p_func)(int, int) = SwapValue1;		// 6) 함수 포인터 (로컬)


	cout << "지역변수 A의 주소 : " << &A << endl;
	cout << "힙포인터 C의 주소 : " << C << endl;
	cout << "힙포인터 D의 주소 : " << D << endl;
	cout << "힙포인터 E의 주소 : " << E << endl;
	cout << "함수포인터의 주소 : " << SwapValue1 << endl;
	cout << "함수포인터 p_func의 주소 : " << p_func << endl;
	cout << "정적변수 B의 주소 : " << &B << endl;
	cout << "전역변수 G의 주소 : " << &G << endl;

	// 사용한 메모리 해제
	free(C);
	delete(D);
	delete[](E);
}

int MyAdd(int a, int b)
{
	cout << "<MyAdd 호출>" << endl;
	return  a + b;
}

int MySub(int a, int b)
{
	cout << "<MySub 호출>" << endl;
	return  a - b;
}

int MyMul(int a, int b)
{
	cout << "<MyMul 호출>" << endl;
	return  a * b;
}

int MyDiv(int a, int b)
{
	cout << "<MyDiv 호출>" << endl;
	return  a / b;
}

