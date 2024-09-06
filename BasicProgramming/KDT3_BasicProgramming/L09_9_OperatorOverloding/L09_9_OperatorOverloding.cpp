// L09_9_OperatorOverloding.cpp :연산자 오버로딩
#include "Sample.h"
#include <iostream>
using namespace std;





// 1) 클래스의 맴버 함수로 정의 하는 방법
// 2) 전역 함수로 정의 하는 방법

int main()
{
    {
        cout << "[연산자 오버로딩]" << endl;

        CTranslation T1(1, 2, 3);
        T1.Print();
        CTranslation T2 = { 4,5,6 };
        T2.Print();
        CTranslation T3 = T1 + T2;
        T3.Print();

        CTranslation T4 = T1 - T2;
        T4.Print();

        CTranslation T5 = T1 / T2;
        T5.Print();

        T3.SetN1(10);
        T3.SetN2(5);

        cout << endl << "[자료형 오버로딩]" << endl;
        double dVal = T3;

        cout << T1;

    }
}
