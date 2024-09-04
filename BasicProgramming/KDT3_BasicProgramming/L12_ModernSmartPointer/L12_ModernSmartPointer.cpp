// L12_ModernSmartPointer.cpp : 스마트 포인터
#include <crtdbg.h>
#include <iostream>

#include "Function.h"

#define _CRTDBG_MAP_ALLOC

using namespace std;

int main()
{

	//int* ptrLeak = new int;

	//delete ptrLeak;



#pragma region 스마트 포인터 / unique_ptr
	cout << "[스마트 포인터 : unique_ptr]" << endl;
	// unique_ptr : 단 하나의 동적할당된 인스턴스만 동시에 존재할 수 있다.
	{
		//ATest* ptrA = new ATest();
		//ptrA->print();
		//delete ptrA;
		// template로 스마트 포인터가 구현되어있다

	
		std::unique_ptr<ATest> Unique(new ATest());
		Unique->print();

		// 블럭을 빠져 나가면 소멸자가 자동으로 호출 => 메모리 관리자가 자동으로 해제 시켜주기 때문에

		// 포인터 메모리를 잘못 사용하는 경우
		// 1) Dangling Pointer : ptrA는 스택영역에 존재, 하지만 기리키는 곳의 메모리는 이미 해제된 경우
		// 2) Pointer Aliasing : 동적할당이 해제된 후 또다른 포인터가 그자리를 가리키는 상황을 말한다
		//						스마트포인터에서 move로만 넘겨주는 이유다
	}
	{
		std::unique_ptr<int> Unique = std::make_unique<int>(10);
		cout << "Unique 값(1) : " << *Unique << endl;
		*Unique = 1000;
		cout << "Unique 값(2) : " << *Unique << endl;
		*Unique.get() = 1234;
		cout << "Unique 값(3) : " << *Unique << endl;
		//unique_ptr<int> Unique2  = Unique;	// 그냥 넣으면 컴파일 에러
		unique_ptr<int> Unique2 = move(Unique);	// 스마트 포인터 이동 => 기존 포인터 메모리 소멸한다
		cout << "Unique2 값(4) : " << *Unique2 << endl;
	}
	// unique_ptr의 custom deleter 정의
	{
		cout << endl;
		std::unique_ptr<int, decltype(&CustomDeleterInt)> Unique(new int(-1000),CustomDeleterInt);
		// 스마트포인터<자료형, 해제될때 부를 함수주소(decleartype)> 이름(동적할당 자료형(값), 해제시 부를 함수)

	}

#pragma endregion

#pragma region 스마트 포인터 / shared_ptr
	cout << "[스마트 포인터 : shared_ptr]" << endl;
	{
		// 1번방식
		//std::shared_ptr<int> SharedPtr1{ std::make_shared<int>(100) };
		// 2번방식
		std::shared_ptr<int> SharedPtr1{ new int,CustomDeleterInt};
		*SharedPtr1 = 100;

		cout << "SharedPtr1 값 : " << *SharedPtr1 << endl;


		shared_ptr<int> SharedPtr2 = SharedPtr1;

		cout << "SharedPtr2 값 : " << *SharedPtr2 << endl;

		*SharedPtr2 = 200;		
		cout << "SharedPtr1 값 : " << *SharedPtr1 << endl;
		cout << "SharedPtr2 값 : " << *SharedPtr2 << endl;

		long Count1 = SharedPtr1.use_count();
		long Count2 = SharedPtr2.use_count();
		// 몇번 공유 했는지 개수 체크

		if (Count1 == Count2)
		{
			cout << "SharedPtr1의 레퍼런스 카운트 : " << Count1 << endl;
		}
	}
	// shared_ptr의 순환 참조 오류 예시
	{
		std::shared_ptr<CircularRef> A = std::make_shared<CircularRef>();
		std::shared_ptr<CircularRef> B = std::make_shared<CircularRef>();
		A->SetRef(B);
		B->SetRef(A);

		long Count1 = A.use_count();
		cout << "A의 레퍼런스 카운트 : " << Count1 << endl;
		// 레퍼런스가 0 이되어야 메모리를 해제하는데 서로가 서로를 참조하니 0이될수가 없어 누구가 생김
	}
#pragma endregion



	// 메모리 누수 발생시 디버그출력 창에 누수가 생겼다 알림과 누수 장소를 알려줌
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();


}
