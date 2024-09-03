// L09_6_VirtualFunction.cpp : 가상함수
#include <iostream>

using namespace std;

class CBase
{
public:
	CBase();
	virtual ~CBase();

	void Print()
	{
		cout << "베이스 Print() " << endl;
	}

	virtual void V_Print()
	{
		cout << "베이스 V_Print() " << endl;

	}
private:

};

CBase::CBase()
{
	cout << "베이스 생성자" << endl;
}

CBase::~CBase()
{
	cout << "베이스 소멸자" << endl;
}

class CDerived : public CBase
{
public:
	CDerived();
	virtual ~CDerived() override;

	void Print()
	{
		cout << "파생1 Print() " << endl;

	}
	virtual void V_Print() override
	{
		cout << "파생1 V_Print() " << endl;

	}

private:

};

CDerived::CDerived()
{
	cout << "파생1 생성자" << endl;

}

CDerived::~CDerived()
{
	cout << "파생1 소멸자" << endl;

}

class CDerived2 : public CDerived
{
public:
	CDerived2();
	virtual ~CDerived2() override;

	virtual void V_Print() override
	{
		cout << "파생 2번 V_Print()" << endl;
	}

private:
	int* pMemoryPool;
};

CDerived2::CDerived2()
{
	pMemoryPool = new int[1024];
	cout << "파생2 생성자" << endl;

}

CDerived2::~CDerived2()
{
	delete[] pMemoryPool;
	cout << "파생2 소멸자" << endl;

}

class A {};
class B { char a; };
class C {
	int a; char b; int c;
};
class D { public: void Test() {} };
class E { public: virtual void Test() {} };


int main()
{
	{
		cout << "[정적 바인딩(Static binding)]" << endl;
		
		CBase* pBase = new CBase;			// 베이스 클래스 객체
		CBase* pDelete = pBase;				// 나중에 딜리트용 저장 객체
		CDerived* pDerived = new CDerived;	// 파생 클래스 객체

		pBase->Print();				
		pBase = pDerived;			// 베이스 포인터를 파생포인터로 변경 => 컴파일 오류없이 주소값 바뀜	
		if (pBase == pDerived)
		{

			pBase->Print();			// virtual이 베이스 클래스에 적혀있지 않았다면 베이스 클래스의 Print로 간다
		}

		delete pBase;		// 파생 클래스 제거
		delete pDelete;	// 임시로 베이스 객체받아 놓은곳


	}

	{
		cout << endl << "[동적 바인딩(Dynamic binding)]" << endl;

		CBase* pBase = new CBase;			// 베이스 클래스 객체
		CBase* pDelete = pBase;				// 나중에 딜리트용 저장 객체
		CDerived* pDerived = new CDerived;	// 파생 클래스 객체


		pBase->V_Print();
		pBase = pDerived;			// 베이스 포인터를 파생포인터로 변경 => 컴파일 오류없이 주소값 바뀜	
		if (pBase == pDerived)
		{

			pBase->V_Print();			
		}

		delete pBase;		// 파생 클래스 제거
		delete pDelete;		// 임시로 베이스 객체받아 놓은곳
	}

	{
		cout << endl << "[동적 바인딩(Dynamic binding) Ex2]" << endl;

		CBase Base;				// 베이스 클래스 객체
		CDerived Derived;		// 파생 클래스 객체
		CBase* pBase = &Base;	// 베이스를 가리키는 포인터
		pBase->V_Print();

		pBase = &Derived;
		pBase->V_Print();

		CDerived2 Derived2;
		pBase = &Derived2;
		pBase->V_Print();
		

	}
	
	// 굉장히 중요한 부분
	{
		cout << endl << "[베이스 소멸자만 진행되는 문제]" << endl;
		CDerived* pDerived = new CDerived;
		CBase* pBase = pDerived;					// 소멸자에 virtual을 적어놓지 않으면 파생 소멸자를 진행하지 않음

		delete pBase;

		CDerived2* pDerived2 = new CDerived2;
		CBase* pBase2 = pDerived2;

		delete pBase2;
	}
	{

		cout << endl << "[클래스 사이즈]" << endl;

		int _size = 0;
		_size = sizeof(A);	// 1byte
		_size = sizeof(B);	// 1byte
		_size = sizeof(C);	// 4byte
		_size = sizeof(D);	// 1byte
		_size = sizeof(E);	// 8byte

		// 클래스의 기본 사이즈는 1byte로 4의 배수 사이즈로 크기가 늘어난다.
		// virtual을 사용하게되면 가상함수 테이블이 생성되어 "_vfptr" 포인트 배열이 들어가기때문에 8byte에서 시작한다
	}
}
