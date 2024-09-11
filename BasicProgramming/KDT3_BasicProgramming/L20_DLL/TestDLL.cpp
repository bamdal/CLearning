#include "pch.h"

int Dll_Sum(int A, int B)
{
	return A + B;
}


int Dll_Game()
{
	cout << "Dll_Game() 호출" << endl;

	CSimpleStack StackObj;
	int UserInput = STACK_COMMAND::CMD_ERROR;
	bool Loop = true;
	while (true) {
		cout << "스택 명령의 번호를 입력하세요 | 1) push 2) pop 3) view 4) Exit" << endl;
		cin >> UserInput;
		switch (UserInput)
		{
		case CMD_ERROR:
			break;
		case CMD_PUSH:
			double i;
			cin >> i;
			StackObj.F_Push();
			break;
		case CMD_POP:
			StackObj.F_Pop();
			break;
		case CMD_OUTPUT:
			StackObj.F_Output();
			break;
		case CMD_EXIT:
			Loop = false;
			break;
		default:
			break;
		}
	}
	return 0;
}