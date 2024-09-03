#pragma once
#include "Charactor.h"
#include <iostream>

using namespace std;

#define SPECIAL_ATTACK_MUL (2)

class CMonster : public CCharactor
{
public:
	CMonster();
	~CMonster();

	virtual void Attack(CCharactor* pTarget) override
	{

	}

	virtual void Attack_Special(CCharactor* pTarget)
	{

	}

	virtual void StatOutput()
	{
		cout << this << "Player의 HP : " << m_iHP << endl;
		cout << this << "Player의 Power : " << m_iPower << endl;
	}
private:

};

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}


// 좀비 =====================================================================================


class CMonster_Zombi : public CMonster
{
public:
	CMonster_Zombi();
	~CMonster_Zombi();

	virtual void Attack(CCharactor* pTarget) override ;			//{}를 여기에 작성하면 아레에 빼놓은 함수랑 충돌
	virtual void Attack_Special(CCharactor* pTarget) override ;


private:

};

CMonster_Zombi::CMonster_Zombi()
{
	m_iHP = 10, m_iPower = 1;
}

CMonster_Zombi::~CMonster_Zombi()
{
}

void CMonster_Zombi::Attack(CCharactor* pTarget)
{
	cout << "물기 공격 데미지 : " << m_iPower << endl;
	if (pTarget != nullptr)
	{
		pTarget->SetDamage(m_iPower);
	}
}

void CMonster_Zombi::Attack_Special(CCharactor* pTarget)
{
	cout << "감염 공격 데미지 : " << m_iPower * SPECIAL_ATTACK_MUL << endl;
	if (pTarget != nullptr)
	{
		pTarget->SetDamage(m_iPower * SPECIAL_ATTACK_MUL);
	}
}

// 골렘 ============================================================

class CMonster_Golem : public CMonster
{
public:
	CMonster_Golem();
	~CMonster_Golem();

	// 시그니처의 변화를 줬으므로 override는 사용못한다.
	virtual void Attack(CPlayer* pTarget);
	virtual void Attack_Special(CPlayer* pTarget);


private:

};

CMonster_Golem::CMonster_Golem() 
{
	m_iHP = 200, m_iPower = 20;
}

CMonster_Golem::~CMonster_Golem()
{
}

void CMonster_Golem::Attack(CPlayer* pTarget)
{
	cout << "바위 공격 데미지 : " << m_iPower << endl;
	if (pTarget != nullptr)
	{
		pTarget->SetDamage(m_iPower);
	}
}

void CMonster_Golem::Attack_Special(CPlayer* pTarget)
{
	cout << "지진 공격 데미지 : " << m_iPower * SPECIAL_ATTACK_MUL << endl;
	if (pTarget != nullptr)
	{
		pTarget->SetDamage(m_iPower * SPECIAL_ATTACK_MUL);

	}
}

