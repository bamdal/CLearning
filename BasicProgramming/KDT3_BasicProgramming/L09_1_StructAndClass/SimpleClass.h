#pragma once

#include <iostream>
using namespace std;

class CSimpleClass
{
    //private: 생략
        // 클래스 멤버 선언 & 초기화 ( 생성자 호출시 맴버 이니셜라이저를 생략하면 여기가 호출( 2 순위 ) )
    int m_iVal1 = 2;
    int m_iVal2 = 2;
    int Age;
    string m_strName;

public: // 이 밑은 public
    // 생성자
    CSimpleClass() : m_iVal1(1), m_iVal2(1) // 가장 먼저 호출( 1순위 ) => 맴버 이니셜라이저
    {
        // 생성자 함수 내부( 3순위 ) / 즉, 앞단(1,2순위)에서 초기화를 해도 여기서 초기화한 값이 최종 반영
        m_iVal1 = 3;
        m_iVal2 = 3;
        Age = 19;
        m_strName = "No name";
    }
    ~CSimpleClass()
    {
        cout << "소멸자 ~CSimpleClass() 호출 : " << m_strName << endl;
    }

    int GetValue1()
    {
        return m_iVal1;
    }
    void SetValue1(int iVal)
    {
        m_iVal1 = iVal;
    }
    int GetValue2()
    {
        return m_iVal2;
    }
    void SetValue2(int iVal)
    {
        m_iVal2 = iVal;
    }

    int GetAge() { return Age; }
    void SetAge(int Age)
    {
        //        Age = Age; // 예시를 위한것 => 이렇게 파라미터랑 맴버변수랑 중복적으로 이름 사용하는건 지양하세요
        this->Age = Age; // this 포인터는 객체 자신을 가리키는 포인터

        cout << "파라미터 Age의 주소 : " << &Age << endl;
        cout << "객체맴버 Age의 주소 : " << &(this->Age) << endl;
    }

    int AddVal();
    void SetName(const char* lpName);
    CSimpleClass* GetThisPtr()
    {
        return this;
    }
};