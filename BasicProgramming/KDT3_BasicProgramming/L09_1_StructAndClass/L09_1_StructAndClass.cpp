#include "SimpleClass.h"
#include <iostream>

using namespace std;

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
#pragma endregion

}
