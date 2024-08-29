#pragma once

#include <iostream>
using namespace std;

enum ECharClass : int
{
	_Empty	= -1,	// 없음(에러)
	Warrior = 0,
	Paladin = 1,
	Mage	= 2,
	Hunter	= 3,
	Rogue	= 4,

	_Max,			// 전체 직업수
};

// 구조체는 하나 이상의 자료형을 조합해서 사용자 정의 타입으로 새로 만들때 이 구조체를 쓴다.
// 캐릭터 구조체
struct MyCharacter
{

	ECharClass ClassType;	// 캐릭터 직업
	int Level;				// 레벨
	int Exp;				// 경험치

	MyCharacter()			// 생성자
	{
		this->ClassType = ECharClass::_Empty;
		this->Level = 0;
		this->Exp = 0;
		cout << "[ 구조체 생성자 자동 호출 ]" << endl;
	}

	void PrintInfo()
	{
		cout << "[ 캐릭터 정보 ]" << endl;

		cout << "1)직업 : ";
		switch (this->ClassType)
		{
		case _Empty:
			cout << "_Empty	" << endl;
			break;
		case Warrior:
			cout << "Warrior " << endl;
			break;
		case Paladin:
			cout << "Paladin " << endl;
			break;
		case Mage:
			cout << "Mage	" << endl;
			break;
		case Hunter:
			cout << "Hunter	" << endl;
			break;
		case Rogue:
			cout << "Rogue	" << endl;
			break;
		default:
			cout << "등록되지 않은 직업 입니다" << endl;
			break;
		}

		cout << "2) 레벨 : " << this->Level << endl;
		cout << "3) 경험치 : " << this->Exp << endl;
	}
};