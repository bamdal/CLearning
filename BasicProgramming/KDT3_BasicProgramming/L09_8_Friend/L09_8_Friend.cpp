// L09_8_Friend.cpp : Friend클래스 & Friend함수
#include <iostream>
#include <string>

using namespace std;
class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	string name;

	friend void SetMyNamePlease(MyClass&, string);	// friend 함수 -> 맴버함수 아님 그냥 방명록 수준으로 그냥 이름만 적어놓은것
													// 앞으로 이 시그니처의 SetMyNamePlease함수를 friend라고 미리 알려주는것
	friend class Manager;	// Manager클래스는 friend

	friend class Manager2;	// 현재 존재하지 않은 클래스를 지정해도 이상없다.
};

MyClass::MyClass()
{
	name = "default name";
}

MyClass::~MyClass()
{
}

void SetMyNamePlease(MyClass& Obj, string str)
{
	Obj.name = str;
	cout << "너의 이름은" << Obj.name << "이다." << endl;
}


class Manager
{
public:
	Manager();
	~Manager();

	void SetYourName(MyClass& Obj, string str)
	{
		Obj.name = str;	// friend이기에 name에 접근 가능
	}

	void ShowYourName(MyClass& Obj)
	{
		cout << "내 이름은" << Obj.name << "이다." << endl;
	}
private:

};

Manager::Manager()
{
}

Manager::~Manager()
{
}

int main()
{
	MyClass me;
	Manager manager;
	manager.ShowYourName(me);
	manager.SetYourName(me, "newName");
	manager.ShowYourName(me);

	int ii = 0;
}

