#include "SimpleClass.h"
#include <iostream>

using namespace std;

// 매크로 함수
#define MY_AGE 20
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARR(p){if(p){ delete[](p); (p)=nullptr;}}
#define SAFE_DELETE_AND_COUT(p) {SAFE_DELETE(p) {std::cout << "메모리 해제완료" << endl;}}

// 구조체와 클래스의 차이 : 구조체는 접근 지정자가 기본적으로 public 으로, 클래스는 접근 지정자가 기본적으로 private이다
struct MyStruct	// 구조체
{

	int Val;
};

class MyClass	// 클래스
{
public:
	int Val;
private:

};

int main()
{

#pragma region L09_1_StructAndClass / 구조체와 클래스의 차이
	{
		cout << "[구조체와 클래스 차이]" << endl;

		MyStruct S;
		S.Val = 100;
		cout << "간단한 구조체 Val : " << S.Val << endl;

		MyClass C;
		C.Val =10;
		cout << "간단한 클래스 Val : " << C.Val << endl;
	}
#pragma endregion

#pragma region L09_1_StructAndClass / 클래스 기초 문법 : 맴버의 초기화 순서
	{
		
		CSimpleClass MyObj;
		cout << "MyObj.GetValue1 : " << MyObj.GetValue1() << endl;
		cout << "MyObj.GetValue2 : " << MyObj.GetValue2() << endl;

		MyObj.SetValue1(100);
		MyObj.SetValue2(50);

		cout << "MyObj.GetValue1 : " << MyObj.GetValue1() << endl;
		cout << "MyObj.GetValue2 : " << MyObj.GetValue2() << endl;

		cout << "MyObj.AddVal : " << MyObj.AddVal() << endl;
	}
	{
		CSimpleClass* ptrObj = new CSimpleClass;
		if (ptrObj != nullptr)
		{
			ptrObj->SetValue1(4);
			ptrObj->SetValue2(1000);
			ptrObj->SetName("My First Class!!");
			cout << "ptrObj->AddVal = " << ptrObj->AddVal() << endl;
			ptrObj->SetAge(25);
			cout << "ptrObj->Age = " << ptrObj->GetAge() << endl;
			if (ptrObj == ptrObj->GetThisPtr())
			{
				cout << "ptrObj 와 ptrObj의 this 포인터의 주소는 같다" << endl;
			}

			delete ptrObj;		// 객체파괴 (소멸자 호출! 중요)
			ptrObj = nullptr;	// 관용적으로 소멸된 포인터의 객체는 다시 nullptr을 넣어준다
			SAFE_DELETE_AND_COUT(ptrObj);
		}
	}
#pragma endregion

}
