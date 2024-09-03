// L10_MordernTypeCasting.cpp : Mordern C++ 형변환 정리/ 중요한건 dynamic_cast<> Down casting과 Up casting
#include <iostream>

using namespace std;

int main()
{
#pragma region 형변환 / 명시적 형변환과 static_cast<>
	{
		cout << "[Type Casting 명시적(강제) 형변환의 위험성]" << endl;
		const int Num = 0;
		// int* ptrNum = &Num;		// 상수의 주소를 가져가지 못하게 컴파일러가 막는다		

		int* ptrNum = (int*)&Num;	// 명시적 형변환으로 강제로 가져올 수 있다.
		*ptrNum = 20;

		cout << "*const int Num의 값 : " << Num << endl;
		cout << "*ptrNum의 값 : " << *ptrNum << endl;



	}

	{
		cout << "[static_cast<>]" << endl;
		const int Num = 0;
		//int* ptrNum = static_cast<int*>(&Num);	// static_cast<>는 명시적 형변환시 논리적으로 맞지 않다면 에러 발생
		int Num2 = 10;
		int* ptrNum2 = static_cast<int*>(&Num2);
		*ptrNum2 = 20;
		cout << "*int Num2의 값 : " << Num2 << endl;
		cout << "*ptrNum2의 값 : " << *ptrNum2 << endl;
	}
#pragma endregion

#pragma region 형변환 / reinterpret_cast(거의 안씀)
	{
		struct Test
		{
			int A;
			int B;
		};

		Test T;
		T.A = 100;
		T.B = 500;
		int* ptr = reinterpret_cast<int*>(&T);

		cout << "구조체 T를 int*형으로 재해석" << endl;
		cout << T.A << endl;
		cout << *ptr << endl;
		cout << *(ptr + 1) << endl;
		*ptr = 300;
		cout << T.A << endl;
		cout << *ptr << endl;
		cout << *(ptr + 1) << endl;
	}
#pragma endregion

#pragma region 형변환 / const_cast(거의 안씀)
	{
		char szData[] = "Assort";
		const char* pData = szData;
		cout << "szData 원래 문자열 : " << pData << endl;
		// pData[0] = 'Q';	// const에 할당불가
		char* pData2 = const_cast<char*>(pData);
		pData2[0] = 'Q';
		cout << "szData 변경 문자열 : " << pData << endl;

	}
#pragma endregion


}

