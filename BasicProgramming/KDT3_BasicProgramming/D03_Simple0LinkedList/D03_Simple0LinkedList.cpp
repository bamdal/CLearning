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
	for (int i = 0; i < 10; i += 2)
	{
		pListObj->F_AscendingInsert(i);
	}

	while (loop)
	{
		cout << "리스트 명령 입력 : 1) 오름차순삽입 2) 삽입 3) 찾기 4) 삭제 5) 내림차순삽입 6) 출력 7) 종료";
		cin >> userInput;
		switch (userInput)
		{
		case LIST_COMMAND::CMD_ERROR:
			break;
		case LIST_COMMAND::CMD_ASCENDING_INSERT:
		{
			cout << "삽입할 데이터";
			cin >> newKey;
			pListObj->F_AscendingInsert(newKey);
		}
			break;
		case LIST_COMMAND::CMD_FRONT_INSERT:
		{
			cout << "삽입할 값 입력 : ";
			cin >> newKey;
			cout << "입력할 위치 값 입력 : ";
			int key=0;
			cin >> key;
			pListObj->F_FrontInsert(newKey, key);
		}
			break;
		case LIST_COMMAND::CMD_FIND:
		{
			cout << "찾을 값을 입력하세요";
			cin >> newKey;
			pListObj->F_Find_Node(newKey);
		}
			break;
		case LIST_COMMAND::CMD_DELETE:
		{
			cout << "삭제 값을 입력하세요";
			cin >> newKey;
			pListObj->F_Node_Delete(newKey);
		}
			break;
		case LIST_COMMAND::CMD_DESCENDING_INSERT:
		{
			cout << "삽입할 데이터";
			cin >> newKey;
			pListObj->F_DescendingInsert(newKey);
		}
			break;
		case LIST_COMMAND::CMD_OUTPUT:
		{
			pListObj->F_Output();
		}
			break;
		case LIST_COMMAND::CMD_EXIT:
		{
			loop = false;
			cout << "프로그램 종료" << endl;
		}
			break;
		default:
			break;
		}
	}

	delete pListObj;
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

}
