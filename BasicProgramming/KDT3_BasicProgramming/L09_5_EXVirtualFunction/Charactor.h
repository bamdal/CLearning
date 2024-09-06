#pragma once
#include <iostream>

using namespace std;

class CCharactor
{
protected:
	int m_iHP;
	int m_iPower;

public:
	 CCharactor();
	~CCharactor();

	void SetDamage(int iDamage)
	{
		m_iHP -= iDamage;
	}

	virtual void Attack(CCharactor* pTarget) {};

	void Print()		// 일반 함수
	{
		cout << " CCharactor::Print() 함수 실행" << endl;
	}
	void Print() const // const 함수 맴버함수 오버로딩 
	{
		cout << " CCharactor::Print() const 함수 실행" << endl;

	}
	void StatOutput() const	// const함수는 오버로딩 가능
	{
		//m_iHP++;
		//SetDamage(10);	// 다른 맴버 함수를 호출해서 변수 수정도 안된다.
		cout << "Player의 HP : " << m_iHP << endl;
		cout << "Player의 Power : " << m_iPower << endl;
	}


private:

};

CCharactor::CCharactor() : m_iHP(1000), m_iPower(100)
{
	//m_iHP = 1000, m_iPower = 100;
}

CCharactor::~CCharactor()
{
}

class CPlayer : public CCharactor
{
public:
	CPlayer();
	~CPlayer();

	void StatOutput() const	// const 키워드 추가시 맴버 함수 내에서 맴버를 수정할수 없게 된다.
	{
		//m_iHP++;
		//SetDamage(10);	// 다른 맴버 함수를 호출해서 변수 수정도 안된다.
		cout << "Player의 HP : " << m_iHP << endl;
		cout << "Player의 Power : " << m_iPower << endl;
	}

	virtual void Attack(CCharactor* pTarget) override
	{
		if (pTarget != nullptr)
		{
			pTarget->SetDamage(m_iPower);
		}
	}

private:

};

CPlayer::CPlayer()
{
	cout << "[Player의 생성자 호출]" << endl;
}

CPlayer::~CPlayer()
{
}