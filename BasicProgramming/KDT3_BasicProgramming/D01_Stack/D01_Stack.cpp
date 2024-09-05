// D01_Stack.cpp : 기본 자료구조 프로그램 <스택>
#include <iostream>

using namespace std;

#define MAX_STACK_SIZE (10)
#define INVALID_STACK_POINTER (-1)

enum STACK_COMMAND :int
{
	CMD_ERROR = 0,	// 잘못된 명령값
	
	CMD_PUSH = 1,	// 스택에 데이터를 넣는다
	CMD_POP = 2,	// 스택에서 데이터를 꺼낸다
	CMD_OUTPUT =3,

	CMD_EXIT = 4,	// 프로그램을 종료한다.
};

class CSimpleStack
{
public:
	CSimpleStack();
	~CSimpleStack();

	void F_Push();
	void F_Pop();
	void F_Output();
	bool CheakEmpty();

private:
	int Container[MAX_STACK_SIZE] = {};	// 스택 컨테이너
	int StackPointer = INVALID_STACK_POINTER;
};

CSimpleStack::CSimpleStack()
{
}

CSimpleStack::~CSimpleStack()
{
}

/// <summary>
/// 데이터 삽입 함수
/// </summary>
void CSimpleStack::F_Push()
{
	if (StackPointer < MAX_STACK_SIZE-1)
	{
		int data;
		cout << "스택에 넣을 숫자를 입력하세요 : ";
		cin >> data;
		StackPointer++;
		Container[StackPointer] = data;

	}
	else
	{
		cout << "스택이 가득 찼습니다." << endl;
	}
}

/// <summary>
/// 데이터 삭제 함수
/// </summary>
void CSimpleStack::F_Pop()
{
	if (CheakEmpty())
	{
		cout << "F_Pop()_" << StackPointer << ": " << Container[StackPointer] << endl;
		Container[StackPointer] = 0;
		StackPointer--;
	}
	else
	{
		cout << "인덱스 최소범위 초과"  << endl;
	}

}

/// <summary>
/// 컨테이너 데이터 출력함수
/// </summary>
void CSimpleStack::F_Output()
{
	cout << "[현재 스택 컨테이너에 들어있는 데이터]" << endl;
	for (int i = StackPointer; i >= 0; i--)
	{
		cout << "index " << i << "번째 데이터 : " << Container[i] << endl;
	}
}

bool CSimpleStack::CheakEmpty()
{
	bool result = true;
	if (!(StackPointer > INVALID_STACK_POINTER))
	{ 
		cout << "Stack Empty" << endl;
		result = false;
	}
	return result;
}

int main()
{
	CSimpleStack StackObj;
	int UserInput = STACK_COMMAND::CMD_ERROR;
	bool Loop = true;

	while (Loop)	//일종의 게임 루프
	{
		cout << "스택 명령의 번호를 입력하세요 | 1) push 2) pop 3) view 4) Exit" << endl;
		cin >> UserInput;	// 사용자 입력을 받아온다 (while 루프 안이지만 사용자의 입력을 대기함)
		switch (UserInput)
		{
		case CMD_ERROR:
			break;
		case CMD_PUSH:
			StackObj.F_Push();
			break;
		case CMD_POP:
			StackObj.F_Pop();
			break;
		case CMD_EXIT:
			Loop = false;
			cout << "프로그램을 종료합니다" << endl;
			break;
		case CMD_OUTPUT:
			StackObj.F_Output();
			break;
		default:
			cout << "지원하지 않는 명령입니다" << endl;
			break;
		}
	}
}
