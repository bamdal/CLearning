// D03_Simple0LinkedList.cpp : 기본 자료구조 프로그램 <Simple Linked List>
#include <iostream>
#include "SimpleLinkedList.h"


using namespace std;



int main()
{
	CSimpleLinkedList* pListObj = new CSimpleLinkedList;

	int userInput = LIST_COMMAND::CMD_ERROR;
	bool loop = true;
	int newKey = 0;
	while (loop)
	{
		cout << "리스트 명령 입력 : 1) 오름차순삽입 2) 삽입 3) 찾기 4) 삭제 5) 내림차순삽입 6) 출력 7) 종료";
		cin >> userInput;
		switch (userInput)
		{
		case LIST_COMMAND::CMD_ERROR:
			break;
		case LIST_COMMAND::CMD_ASCENDING_INSERT:
			cout << "삽입할 데이터";
			cin >> newKey;
			pListObj->F_AscendingInsert(newKey);
			break;
		case LIST_COMMAND::CMD_FRONT_INSERT:
			break;
		case LIST_COMMAND::CMD_FIND:
			break;
		case LIST_COMMAND::CMD_DELETE:
			break;
		case LIST_COMMAND::CMD_DESCENDING_INSERT:
			cout << "삽입할 데이터";
			cin >> newKey;
			pListObj->F_DescendingInsert(newKey);
			break;
		case LIST_COMMAND::CMD_OUTPUT:
			pListObj->F_Output();
			break;
		case LIST_COMMAND::CMD_EXIT:
			loop = false;
			cout << "프로그램 종료" << endl;
			break;
		default:
			break;
		}
	}

	delete pListObj;
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

}
