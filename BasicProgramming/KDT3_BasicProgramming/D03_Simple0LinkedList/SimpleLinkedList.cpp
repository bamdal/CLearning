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
	CNode* pStart = nullptr;
	CNode* pEnd = nullptr;
	pEnd = m_pHead->pNext;

	while (pEnd != m_pTail)
	{
		pStart = pEnd;
		pEnd = pEnd->pNext;
		delete pStart;
	}
	m_pHead->pNext = m_pTail;


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

/// <summary>
/// 특정값 앞에다 insert하기
/// </summary>
/// <param name="newKey">추가할 키값</param>
/// <param name="key">기존 키값</param>
void CSimpleLinkedList::F_FrontInsert(int newKey, int key)
{
	CNode* pPrevious = m_pHead;
	CNode* pStart = m_pHead->pNext;
	while (pStart != m_pTail && pStart->Key != key)
	{
		pPrevious = pStart;
		pStart = pStart->pNext;
	}

	if (pStart != m_pTail)
	{
		CNode* pNode = new CNode;
		pNode->Key = newKey;
		pNode->pNext = pStart;
		pPrevious->pNext = pNode;
	}


}

/// <summary>
/// 특정값 뒤에 insert하기
/// </summary>
/// <param name="newKey"></param>
/// <param name="key"></param>
void CSimpleLinkedList::F_BackInsert(int newKey, int key)
{
	CNode* pPrevious = m_pHead;
	CNode* pStart = m_pHead->pNext;
	while (pStart != m_pTail && pStart->Key != key)
	{
		pPrevious = pStart;
		pStart = pStart->pNext;
	}

	if (pStart != m_pTail)
	{
		CNode* pNode = new CNode;
		pNode->Key = newKey;
		pNode->pNext = pStart->pNext;
		pStart->pNext = pNode;
	}


}


/// <summary>
/// 해당 키값을 찾기
/// </summary>
/// <param name="key">찾을 키값</param>
void CSimpleLinkedList::F_Find_Node(int key)
{
	int index = 0;
	CNode* pStart = m_pHead->pNext;
	while(pStart != m_pTail && pStart->Key != key)
	{
		index++;
		pStart = pStart->pNext;
	}

	if (pStart != m_pTail)
	{
		cout << format("리스트의 인덱스 [{}]에 있는 데이터 {}이(가) 발견\n", index, key);
	}
	else
	{
		cout << format("{}은 리스트에 없습니다\n", key);
	}

}

/// <summary>
/// 해당 키값을 삭제
/// </summary>
/// <param name="key">삭제할 키 값</param>
void CSimpleLinkedList::F_Node_Delete(int key)
{
	int index = 0;
	CNode* pStart = m_pHead->pNext;
	CNode* pPrevious = m_pHead;
	while (pStart != m_pTail && pStart->Key != key)
	{
		index++;
		pPrevious = pStart;
		pStart = pStart->pNext;
	}

	if (pStart != m_pTail)
	{
		cout << format("리스트의 인덱스 [{}]에 있는 데이터 {}이(가) 삭제\n", index, key);
		pPrevious->pNext = pStart->pNext;
		delete pStart;
	}
	else
	{
		cout << format("{}은 리스트에 없어 지울 수 없습니다\n", key);
	}

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



