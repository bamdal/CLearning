// L10_MordernTypeCasting.cpp : Mordern C++ 형변환 정리/ 중요한건 dynamic_cast<> Down casting과 Up casting
#include <iostream>

using namespace std;

class CBase
{
public:
	CBase();
	virtual ~CBase();

	 void Print()
	{
		cout << "CBase의 출력 함수" << endl;
	}

private:

};

CBase::CBase()
{
	cout << "CBase() 생성자 호출" << endl;
}

CBase::~CBase()
{
	cout << "~CBase() 소멸자 호출" << endl;
}

class CDerived : public CBase
{
public:
	CDerived();
	virtual ~CDerived() override;

	 void Print()
	{
		cout << "CDerived의 출력 함수" << endl;
	}
private:

};

CDerived::CDerived()
{
	cout << "CDerived() 생성자 호출" << endl;
}

CDerived::~CDerived()
{
	cout << "~CDerived() 소멸자 호출" << endl;
}

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

#pragma region 형변환 / dynamic_cast<>
	// dynamic_cast<> safe downcasting(안전한 다운캐스팅)에 사용
	// => 베이스 클래스의 포인터에서 파생 클래스의 포인터로 다운캐스팅해주는 연산자
	// => 다만 부모 클래스가 뭘 가리키고 있는지가 관건
	// => 런타임 연산자기 때문에 캐스팅 비용이 조금 있다.
	{
		CBase* pBase = new CBase;
		pBase->Print();

		CBase* pDelete = pBase;
		CDerived* Obj = new CDerived;	// pBase 가 파생이면 dynamic_cast<>의 성공
		pBase = Obj;					// pBase를 업 캐스팅 하여 dynamic_cast로 다운 캐스팅이 될수있게 한다.

		//dynamic_cast<> 는 실행중에 유효하지 않은 포인터를 알려준다
		CDerived* pDerived = dynamic_cast<CDerived*>(pBase);
		if (pDerived == nullptr)
		{
			// CBase()를 통해 생성했기 때문 => 즉 CDerived 생성자를 호출한 곳이 없다.
			cout << "Runtime Error!" << endl;
		}
		else
		{
			pDerived->Print();

		}


		delete pDelete;
		delete pBase;
		
	}

	{



		CBase* pBase = new CDerived;
		if (pBase == nullptr)
		{
			
			cout << "Runtime Error!" << endl;
		}
		else
		{
			pBase->Print();	// 정상(베이스의 Print가 출력된다) => 만약 베이스만 virtual Print() 하면 파생 Print() 호출
							// 만약 파생만 virtual이면 부모의 print 출력

		}

		CDerived* pDerived = dynamic_cast<CDerived*>(pBase);
		if (pDerived == nullptr)
		{
			cout << "Runtime Error!" << endl;
		}
		else
		{
			// 파생 클래스로 생성했기 때문 => 즉, CDerived() 생성자가 호출 됬으니 다운 캐스팅이 가능
			pDerived->Print();
		}

		delete pBase;
	}

	//dynamic_cast<> 업 캐스팅
	{
		CDerived* pDerived = new CDerived;
		pDerived->Print();
		// CDerived를 CBase로 형변환 시도 static_cast<> 성공체크하기
		CBase* pBase = static_cast<CBase*>(pDerived);

		if (pBase == nullptr)
		{
			cout << "Runtime Error!" << endl;
		}
		else
		{
			pBase->Print();	// 베이스 클래스의 Print()출력
		}
	

		delete pDerived;
	}
#pragma endregion

}

