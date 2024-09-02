#pragma once
#include <iostream>

using namespace std;

class CSimpleClass
{
	int m_iVal1;
	int m_iVal2;
	int Age;
public :
	CSimpleClass() : m_iVal1(1)
	{
		m_iVal2 = 3;
	}
	~CSimpleClass()
	{
	}


	int GetValue1(){ return m_iVal1; }
	int GetValue2() { return m_iVal2; }
	void SetValue1(int iVal){ m_iVal1 = iVal; }
	void SetValue2(int iVal) {m_iVal2 = iVal; }

	int GetAge() { return Age; }
	void SetAge(int Age)
	{
		this->Age = Age;
		cout << "파라미터 Age :" << &Age << endl;
		cout << "객체맴버 Age :" << &(this->Age) << endl;
	}

	int Age();
	int AddVal();
	void SetName(const char* IpName);
};
