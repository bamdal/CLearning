#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAX_DATA_SIZE (64)

class ATest
{
public:
	ATest();
	virtual ~ATest();

	void print()
	{
		cout << "ATest::Print() 호출" << endl;
	}
	

private:

};

ATest::ATest()
{
}

ATest::~ATest()
{
	cout << "ATest 소멸자 호출" << endl;
}

void CustomDeleterInt(int* InPointer)
{
	cout << "CustomDeleterInt() : 자동으로 메모리 해제 " << to_string(*InPointer) << endl;
	delete InPointer;
}

/// <summary>
/// 순환 참조 예시용 클래스
/// </summary>
class CircularRef
{
	int* pDATA = nullptr;
	std::shared_ptr<CircularRef> pRef;

public:
	CircularRef()
	{
		pDATA = new int[MAX_DATA_SIZE];
	}
	virtual ~CircularRef()
	{
		delete[] pDATA;
	}

	void SetRef(std::shared_ptr<CircularRef> ptr)
	{
		pRef = ptr;
	}

	void Print()
	{
		cout << "이 클래스는 오류다" << endl;
	}
};