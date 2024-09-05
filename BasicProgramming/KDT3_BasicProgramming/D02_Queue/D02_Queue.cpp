// D02_Queue.cpp : 기본 자료구조 프로그램 <Queue>
#include <iostream>
#include <format>

#define MAX_QUEUE_SIZE (10)


using namespace std;

enum QUEUE_COMMAND : int
{
	CMD_ERROR = 0,	// 잘못된 명령값

	CMD_ASCENDING_INSERT = 1,	// 큐에 데이터를 넣는다
	CMD_DESCENDING_INSERT = 2,	// 큐에서 데이터를 꺼낸다
	CMD_OUTPUT = 3,

	CMD_EXIT = 4,	// 프로그램을 종료한다.
};


class CSimpleQueue
{
public:
	CSimpleQueue();
	~CSimpleQueue();

	void F_EnQueue();
	void F_DeQueue();
	void F_Output();
	bool F_CheakEmpty();

private:
	int Container[MAX_QUEUE_SIZE] = {};			// 큐 컨테이너
	const int QueuePointer = 0;					// 큐 포인터(항상 배열의 첫번째 인덱스)
	int DataCount = 0;							// 큐에 담긴 데이터 개수
};

CSimpleQueue::CSimpleQueue()
{
}

CSimpleQueue::~CSimpleQueue()
{
}
/// <summary>
/// 큐에 데이터 넣기
/// </summary>
void CSimpleQueue::F_EnQueue()
{
	if (DataCount < MAX_QUEUE_SIZE)
	{
		int data;
		cout << "큐에 넣을 숫자 입력하기 : ";
		cin >> data;
		Container[DataCount] = data;
		DataCount++;

	}
	else
	{
		cout << "큐가 가득 찼다" << endl;
	}
}

/// <summary>
/// 큐에 데이터 빼기
/// </summary>
void CSimpleQueue::F_DeQueue()
{
	if (!F_CheakEmpty())
	{
		int Data = Container[QueuePointer];
		cout << "큐포인터가 가리키는 값 : " << Data << endl;
		cout << format("큐에서 {}데이터를 빼냈다\n", Data);
		for (int i = 0; i < DataCount; i++)
		{
			Container[i] = Container[i + 1];	// 뒤에있는 데이터를 하나씩 앞으로 가져온다
		}
		DataCount--;
	}
}

/// <summary>
/// 큐 전체 내용 확인
/// </summary>
void CSimpleQueue::F_Output()
{
	cout << "[현재 큐에 들어있는 데이터] " << DataCount << endl;
	string strOutput;
	for (int i = 0; i < DataCount; i++)
	{
		strOutput += format("[{} : {}]", i, Container[i]);
		cout << Container[i];
		if (i != DataCount - 1)
		{
			cout << ", ";
			strOutput += ", ";
		}
	}
	cout << endl;
	cout << strOutput.c_str() << endl;
}

/// <summary>
/// 데이터가 비었는지 체크하는 함수
/// </summary>
/// <returns>true 비어있다, false 들어있다</returns>
bool CSimpleQueue::F_CheakEmpty()
{
	return !(DataCount > 0);
}



int main()
{
	bool Loop = true;
	int userInput = QUEUE_COMMAND::CMD_ERROR;

	CSimpleQueue QueueObj;


	while (Loop)
	{
		cout << "큐 명령의 번호를 입력하세요 | 1) EnQueue 2) DeQueue 3) view 4) Exit" << endl;
		cin >> userInput;
		switch (userInput)
		{
		case QUEUE_COMMAND::CMD_ERROR:
			cout << "지원하지 않는 명령입니다" << endl;
			break;
		case QUEUE_COMMAND::CMD_ASCENDING_INSERT:
			QueueObj.F_EnQueue();
			break;
		case QUEUE_COMMAND::CMD_DESCENDING_INSERT:
			QueueObj.F_DeQueue();
			break;
		case QUEUE_COMMAND::CMD_OUTPUT:
			QueueObj.F_Output();
			break;
		case QUEUE_COMMAND::CMD_EXIT:
			Loop = false;
			cout << "프로그램을 종료합니다" << endl;
			break;
		default:
			cout << "지원하지 않는 명령입니다" << endl;
			break;
		}
	}
}

