#include "TestFunc.h"
#include "../L06_Structure/MyCharacter.h"
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

#pragma region L07_Pointer_Array / 배열
	// 같은 자료형의 변수 여러 개를 연속으로 늘어놓은 자료구조
	{
		cout << "[ 배열 원소의 값, 주소 출력 ]" << endl;
		//int iArr[5];				// 안에 쓰레기 값이 들어감
		//int iArr[5] = {};			// 각 원소들을 0으로 초기화 된다.
		//int iArr[5] = {0,1,2,};	// 작성 안된 부분의 원소는 자동으로 0 초기화
		int iArr[5] = {0,1,2,3,4};
		iArr[0] = 5;				// 각 원소를 개별적으로 초기화
		//int iArr[5] = {0,1,2,3,4,5};	// 오류 C2078 이니셜라이저 값이 너무 많습니다

		// 배열 인덱스는 0 ~ n-1 까지
		int iSum = 0;
		for (int i = 0; i < 5; i++)
		{
			cout << "iArr[" << i << "]의 값 : " << iArr[i] << ", 주소 값 : " << &iArr[i] << endl;
			iSum += iArr[i];
		}

		cout << "iSum의 값 : " << iSum << endl;

		cout << "배열 이름 iArr의 주소 : " << iArr << endl;

		iSum = 0;
		int* iPtr = iArr; // 배열의 첫번째 원소의 주소 대입
		//int* iPtr = &iArr[O]; // 배열의 첫번째 원소의 주소 대입
		for (int i = 0; i < 5; i++)
		{
			cout << "iPtr + " << i << "의 값 :" << *iPtr << ", 주소 :" << iPtr << endl;
			iSum += *iPtr;
			iPtr++;
			
		}
		cout << "iSum의 값 : " << iSum << endl;

		cout << "[ 2차원 배열 원소의 값, 주소 출력 ]" << endl;
		// 2차원 배열
		int iArr2[8][5];
		for (int i = 0; i < sizeof(iArr2)/ sizeof(iArr2[0]); i++)
		{
			for (int j = 0; j < sizeof(iArr2[0]) / sizeof(int); j++)
			{
				iArr2[i][j] = i * 2 + j;
				cout << "iArr2[" << i << "][" << j << "]의 값 : " << iArr2[i][j] << ", 주소 " << &iArr2[i][j] << endl;;
			}

		}

	}
#pragma endregion

#pragma region L07_Pointer_Array / 포인터와 배열의 크기
	{
		cout << "[ 포인터와 배열의 크기 ]" << endl;
		int iArr[10] = { 1, };
		int* iPtr = iArr;
		short sArr[10] = {};
		short* sPtr = sArr;
		cout << "*iPtr = " << *iPtr << ", 가리키는 주소 : " << iPtr << endl;
		cout << "iArr[0] = " << iArr[0] << ", 배열의 주소 : " << iArr << endl;

		cout << "iPtr의 사이즈 : " << sizeof(iPtr) << endl;
		cout << "iArr의 사이즈 : " << sizeof(iArr) << endl;
		cout << "sPtr의 사이즈 : " << sizeof(sPtr) << endl;
		cout << "sArr[10]의 사이즈 : " << sizeof(sArr) << endl;

		// 포인터 변수에 배열의 시작 주소를 넣어서 둘이 같은 주소를 가리키고 있지만
		// 포인터는 (int*) 타입 / 배열은 int[10] 타임으로 엄연히 다르다
	}
#pragma endregion

#pragma region L07_Pointer_Array / 문자열
	{
		char szData[6] = {'H','E','L','L','O',0};
		char szData2[] = "Hello";	// 끝에 null 문자 (0값)가 들어가 있다 => null 문자가 문자의 끝을 알림

		cout << "문자열 길이 : " << strlen(szData) << endl;
		cout << "문자열 크기 : " << sizeof(szData) << endl;
		cout << "문자열 값 : " << szData << endl;


		cout << "문자열 길이 : " << strlen(szData2) << endl;
		cout << "문자열 크기 : " << sizeof(szData2) << endl;
		cout << "문자열 값 : " << szData2 << endl;

		char* ptrData = szData2;
		cout << "ptrData의 크기" << szData2 << endl;
		*ptrData = 'K';
		cout << "문자열 값 : " << szData2 << endl;
		*(ptrData+2) = 'M';
		cout << "문자열 값 : " << szData2 << endl;

	}
#pragma endregion

#pragma region L07_Pointer_Array / Call by value, Call by reference
	{
		cout << "[ Call by value, Call by reference ]" << endl;

		int iA = 200, iB = 10;
		cout << "<최초값>" << endl;
		cout << "iA : " << iA << ", iB : " << iB << endl;
		SwapValue1(iA,iB);
		cout << "<SwapValue1 호출 후>" << endl;
		cout << "iA : " << iA << ", iB : " << iB << endl;

		SwapValue2(&iA, &iB);
		cout << "<SwapValue2 호출 후>" << endl;
		cout << "iA : " << iA << ", iB : " << iB << endl;

		SwapReference(iA, iB);
		cout << "<SwapReference 호출 후>" << endl;
		cout << "iA : " << iA << ", iB : " << iB << endl;

		cout << "<Reference 규칙>" << endl;
		int& iC = iA;
		cout << "iC 는 iA의 레퍼런스 " << &iC << ", " << &iA << endl;
		iC = iB;
		cout << "iC는 항상 iA의 레퍼런스이다" << &iC << ", " << &iB << endl;

		int iX = 123;
		iC = iX;
		cout << "iC의 레퍼런스는 변경이 안됨" << &iC << ", " << &iX << endl;
	}
#pragma endregion

#pragma region L07_Pointer_Array / 구조체 포인터, 구조체 배열
	{
		cout << endl << "[ 구조체 포인터 ]" << endl;

		MyCharacter NewChar;
		NewChar.PrintInfo();
		
		MyCharacter* ptrChar = &NewChar;
		ptrChar->ClassType = ECharClass::Paladin;
		ptrChar->Level = 10;
		ptrChar->Exp = 30000;
		ptrChar->PrintInfo();

		cout << endl << "[ 구조체 배열과 포인터 ]" << endl;
		const int iPartyPlayerMax = 5;
		MyCharacter Party[iPartyPlayerMax];

		for (int i = 0; i < iPartyPlayerMax; i++)
		{
			ptrChar = &Party[i];
			ptrChar->ClassType = (ECharClass)i;
			ptrChar->Level = ((i + 1) * 2);
			ptrChar->Exp = ((i + 1) * 100);
			ptrChar->PrintInfo();
		}
	}
#pragma endregion

#pragma region L07_Pointer_Array / 동적 메모리 할당
	{
		cout << "[ C방식의 동적할당 ]" << endl;
		int* ptrA = (int*)malloc(sizeof(int));	// int(4Byte) 만큼 Heap영역에 int로 형변환 후 동적메모리 할당
												// malloc은 뭐든 형변환해서 사용가능
		
		if (ptrA != nullptr)					// 동적 할당은 [반드시] nullptr 인지 체크해야 한다
		{
			*ptrA = 100;
			cout << "*ptrA의 값 : " << *ptrA << ", ptrA의 주소" << ptrA << endl;
		}

		free(ptrA);								// 동적할당한 메모리는 반드시 해제한다.
	}
#pragma endregion


}

