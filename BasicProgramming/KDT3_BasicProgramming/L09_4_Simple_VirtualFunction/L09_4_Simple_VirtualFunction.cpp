// L09_4_Simple_VirtualFunction.cpp : 간단한 가상함수
#include <iostream>

using namespace std;

class A
{
public:
	A();
	~A();

	virtual void Attack()	// virtual 선언 : 앞으로 나들 상속받는 클래스들의 Attack()을 가상 함수로 지정 하겠다.
	{
		cout << "A : Attack() 호출 : 검 휘두르기" << endl;
	}

private:

};

A::A()
{
}

A::~A()
{
}

class B : public A
{
public:
	B();
	~B();

	// 자식은 virtual을 안적어도 되지만 계속 상속을 받거나 한 상황에서 가상함수인지 판단이 힘드므로 관례적으로 적어준다.
	virtual void Attack() override			// override 키워드 : 자식클래스에서 이 함수는 부모로부터 상속받아 오버라이딩한 함수다.
	{

		cout << "B : Attack() 호출 : 검 휘두르기" << endl;
	}
	

private:

};

B::B()
{
}

B::~B()
{
}

class C : public A
{
public:
	virtual void Attack() override
	{
		cout << "C : Attack() 호출 : 화염구 날리기" << endl;
	}
};

int main()
{
	{
		cout << "[맴버 함수의 정적(static) 바인딩" << endl;
		// 정적 바인딩 : 클래스에서 맴버 함수 정의시 컴파일 타임에 함수의 호출 주소가 이미 결정나는것
		// => 그래서 호출하면 해당 함수가 실행

		A ObjA;
		ObjA.Attack();

		B ObjB;
		ObjB.Attack();
	}

	{
		// 자식의 주소로 부모의 포인터는 만들수있지만 반대는 안됨 부모는 자식이 뭔지 모름
		// virtual 작성시 자식의 재정의된 함수로 간다.

		cout << "[맴버 함수의 동적(dynamic) 바인딩" << endl;

		B ObjB;
		A* pObjA = &ObjB;
		pObjA->Attack();
		C ObjC;
		pObjA = &ObjC;
		pObjA->Attack();
	}
}

