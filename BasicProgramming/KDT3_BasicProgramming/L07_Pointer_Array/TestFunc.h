#pragma once

#include <iostream>
using namespace std;


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

void SwapValue1(float A, float B)
{
	cout << A << ", " << B << endl;
	A += B;
	B = A - B;
	A = A - B;
	cout << A << ", " << B << endl;
}

// call by reference 
void SwapValue2(int* A, int* B)
{
	cout << *A << ", " << *B << endl;
	*A ^= *B;
	*B = *A ^ *B;
	*A = *A ^ *B;
	cout << *A << ", " << *B << endl;
}

void SwapReference(int &A, int &B)
{
	int iTemp = A;
	A = B;
	B = iTemp;
}
