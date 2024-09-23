// L09_7_PureVirtualFuctioin.cpp : 순수 가상함수
#include <iostream>

using namespace std;

class AWarrior
{
public:
	AWarrior();
	~AWarrior();

	virtual void Attack()
	{
		cout << "AWarrior의 Attack()" << endl;
	}

	virtual void Parrying()
	{
		cout << "AWarrior의 Parrying()" << endl;
	}

	// 순수 가상함수란 베이스클래스에서 파생되는 클래스들한테 모두 적용하는 함수
	virtual void Move() = 0;	// 순수가상함수
	virtual void Jump() = 0;
private:

};

AWarrior::AWarrior()
{
}

AWarrior::~AWarrior()
{
}

class APlayer : public AWarrior
{
public:
	APlayer();
	~APlayer();

	virtual void Attack() override
	{
		cout << "APlayer의 Attack() + 3콤보" << endl;

	}

	virtual void Parrying() override
	{
		cout << "APlayer의 Parrying() + 앞잡" << endl;

	}

	virtual void Move() override 
	{
		cout << "반드시 구현해야 하는 순수 가상함수 Move()" << endl;
	}

	virtual void Jump() override
	{
		cout << "반드시 구현해야 하는 순수 가상함수 Jump()" << endl;


	}

	void PrintAction()
	{
		Move();
		Jump();
		Attack();
		Parrying();
	}

private:

};

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}
int main()
{
	// 순수가상함수가 적히면 추상클래스가 되어서 객체 선언이 불가능해진다
	// AWarrior* w = new AWarrior;

	APlayer* pPlayer = new APlayer;
	pPlayer->PrintAction();
	delete pPlayer;
}

