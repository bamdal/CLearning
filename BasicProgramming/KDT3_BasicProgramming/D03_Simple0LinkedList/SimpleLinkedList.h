#pragma once

#include <iostream>
#include <format>
using namespace std;

enum LIST_COMMAND :int
{
	CMD_ERROR = 0,				// 잘못된 명령값

	CMD_ASCENDING_INSERT = 1,	// 리스트에 데이터를 오름차순으로 자동 삽입
	CMD_FRONT_INSERT = 2,		// 리스트에 데이터를 특정 Key값 앞에 삽입
	CMD_FIND = 3,				// 리스트내 특정 Key값의 노드 찾기
	CMD_DELETE = 4,				// 리스트내 특정 Key값의 노드 삭제
	CMD_DESCENDING_INSERT,		// 리스트에 데이터를 내림차순으로 자동 삽입

	CMD_OUTPUT,					// 현재 리스트 데이터 출력

	CMD_EXIT,					// 프로그램을 종료한다.

};

class CNode
{
public:
	CNode();
	~CNode();

	int Key = 0;
	CNode* pNext = nullptr;
private:

};


class CSimpleLinkedList
{
public:
	CSimpleLinkedList();
	virtual ~CSimpleLinkedList();

	void F_AscendingInsert(int newKey);
	void F_FrontInsert(int newKey, int key);
	void F_Find_Node(int key);

	void F_Node_Delete(int key);

	void F_DescendingInsert(int newkey);


	void F_Output(CNode* = nullptr);

private:
	CNode* m_pHead;
	CNode* m_pTail;
};

