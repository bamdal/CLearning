#include "SimpleLinkedList.h"


CNode::CNode()
{
}

CNode::~CNode()
{
}


CSimpleLinkedList::CSimpleLinkedList()
{
	m_pHead = new CNode;
	m_pTail = new CNode;
	m_pHead->pNext = m_pTail;
	m_pTail->pNext = m_pTail;
}

CSimpleLinkedList::~CSimpleLinkedList()
{
	delete m_pHead;
	delete m_pTail;
}

void CSimpleLinkedList::F_AscendingInsert(int newKey)
{
	CNode* pPrevious = m_pHead;
	CNode* pStart = pPrevious->pNext;
	// 새로 삽입할 newKey가 기존 리스트에 저장된 값보다 크거나 같을때
	while (pStart != m_pTail && newKey >= pStart->Key)
	{
		pPrevious = pPrevious->pNext;
		pStart = pPrevious->pNext;
	}

	CNode* pNode = new CNode;

	pPrevious->pNext = pNode;

	pNode->pNext = pStart;
	pNode->Key = newKey;

}

void CSimpleLinkedList::F_FrontInsert(int newKey, int key)
{
}

void CSimpleLinkedList::F_Find_Node(int key)
{
}


void CSimpleLinkedList::F_Node_Delete(int key)
{
}

void CSimpleLinkedList::F_DescendingInsert(int newKey)
{
	CNode* pPrevious = m_pHead;
	CNode* pStart = pPrevious->pNext;
	// 새로 삽입할 newKey가 기존 리스트에 저장된 값보다 크거나 같을때
	while (pStart != m_pTail && newKey <= pStart->Key)
	{
		pPrevious = pPrevious->pNext;
		pStart = pPrevious->pNext;
	}

	CNode* pNode = new CNode;

	pPrevious->pNext = pNode;

	pNode->pNext = pStart;
	pNode->Key = newKey;
}

void CSimpleLinkedList::F_Output(CNode* pStart)
{
	cout << "[현재 리스트 컨테이너 안에 있는 데이터]" << endl;

	if (pStart == nullptr)
	{
		pStart = m_pHead->pNext;
	}

	string strOutput;
	while (pStart != m_pTail)
	{
		if (pStart != nullptr)
		{
			strOutput += format("[{}]", pStart->Key);
			if (pStart->pNext != m_pTail)
			{
				strOutput += " => ";
			}
			pStart = pStart->pNext;
		}
	}

	cout << strOutput.c_str() << endl;
}



