#include <iostream>
using namespace std;

// 클래스 상속
class CCharacter
{
private:
	int ID;		// 외부접근불가
protected:
	int HP;		// 파생(자식) 클래스까지 접근
public:
	int Power;	// 모든 곳에서 접근가능


public:
	CCharacter() : ID(-1), HP(100), Power(10)
	{
		cout << "[Character의 생성자 호출]" << endl;
	}

	int GetID() { return ID; }
	void SetID(int _id) { ID = _id; }
	int GetHP() { return HP; }
	void SetHP(int _hp) { HP = _hp; }
	int GetPower() { return Power; }
	void SetPower(int _power) { Power = _power; }
};

// 상속 접근 지정자
//class CPlayer : private CCharacter		// 베이스의 public,protected속성들이 private로 변경된다. => is-a 관계를 맺지 않으려 할 때 
//class CPlayer : protected CCharacter		// 베이스의 public속성을 protected로 지정된다(private)는 유지 => 몇몇 맴버는 is->a 관계를 유지할 때
class CPlayer : public CCharacter			// 베이스 클래스의 접근지정자 그대로 상속 -> is->a관계를 맺겠다
{
	string Name;
public:
	CPlayer();
	~CPlayer();

	void SetName(std::string& name)
	{
		Name = name;
	}

	void SetName(const char* pStr)	// string pStr == const char* pStr
	{
		Name = pStr;
	}
	void StatOutput()
	{
		// 부모 클래스 맴버
		cout << "Player의 ID : " << GetID() << endl;
		cout << "Player의 HP : " << HP << endl;
		cout << "Player의 Power : " << Power << endl;

		// 자식 클래스 맴버
		cout << "Player의 Name : " << Name << endl;
	}

private:

};

CPlayer::CPlayer()
{
	cout << "[Player의 생성자 호출]" << endl;
}

CPlayer::~CPlayer()
{
	cout << "[Player의 소멸자 호출]" << endl;

}

int main()
{
	CPlayer Hero;
	Hero.SetID(10);
	Hero.SetHP(3000);
	Hero.SetPower(400);
	Hero.SetName("NewName");
	Hero.StatOutput();
}
