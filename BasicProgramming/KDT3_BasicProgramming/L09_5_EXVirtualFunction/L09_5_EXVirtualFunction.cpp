// L09_5_EXVirtualFunction.cpp : 가상함수 연습
#include "Monster.h"
#include <iostream>

using namespace std;

int main()
{
    CPlayer Hero;
    Hero.StatOutput();

    CMonster_Zombi Zombi;
    CMonster_Golem Golem;

    cout << "[몬스터의 공격]" << endl;
    Zombi.Attack(&Hero);
    Zombi.Attack_Special(&Hero);
    Golem.Attack(&Hero);
    Golem.Attack_Special(&Hero);
    Hero.StatOutput();

    Hero.Attack(&Zombi);
    Zombi.StatOutput();
}

