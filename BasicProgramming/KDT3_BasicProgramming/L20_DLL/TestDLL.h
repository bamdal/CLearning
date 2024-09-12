#pragma once

#ifdef TEST_DLL
#define MYDLL_API __declspec(dllexport)		// DLL 외부 프로그램에 노출하겠다(즉, 이 DLL을 로딩한 프로그램이 접근하게 해줌)
#else
#define MYDLL_API __declspec(dllimport)		// DLL을 사용하는 외부 프로그램이 dllexport로 선언된 곳에 접근하겠다
#endif //  TEST_DLL

// extern "C" : C언어처럼 Name Mangling을 수행하지 않겠다. => Explicit Linking : 명시적 링킹
// Name Mangling : 컴파일러에 의해 이름이 변형되는 규칙 (calling convention에 영향을 받음)
// C++은 함수 오버로딩 지원 => 링커가 오버로딩된 함수들의 이름을 변경하여 구분 & 호출
// 그러나 보통 DLL에서는 복잡하니까 Explicit Linking(명시적 링킹)을 사용 
// extern "C" {}	// {} 안에 강 써놓으면 일일히 extern "C" 안해도 됨
extern "C" MYDLL_API int Dll_Sum(int A, int B);
extern "C" MYDLL_API int Dll_Game();

#define MAX_STACK_SIZE (10)
#define INVALID_STACK_POINTER (-1)
#include <iostream>
using namespace std;

enum STACK_COMMAND :int
{
	CMD_ERROR = 0,	// 잘못된 명령값

	CMD_PUSH = 1,	// 스택에 데이터를 넣는다
	CMD_POP = 2,	// 스택에서 데이터를 꺼낸다
	CMD_OUTPUT = 3,

	CMD_EXIT = 4,	// 프로그램을 종료한다.
};
class CSimpleStack
{
public:


	void F_Push()
	{
		if (StackPointer < MAX_STACK_SIZE - 1)
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
	};
	void F_Pop()
	{
		if (CheakEmpty())
		{
			cout << "F_Pop()_" << StackPointer << ": " << Container[StackPointer] << endl;
			Container[StackPointer] = 0;
			StackPointer--;
		}
		else
		{
			cout << "인덱스 최소범위 초과" << endl;
		}
	};
	void F_Output()
	{
		cout << "[현재 스택 컨테이너에 들어있는 데이터]" << endl;
		for (int i = StackPointer; i >= 0; i--)
		{
			cout << "index " << i << "번째 데이터 : " << Container[i] << endl;
		}
	};
	bool CheakEmpty()
	{
		bool result = true;
		if (!(StackPointer > INVALID_STACK_POINTER))
		{
			cout << "Stack Empty" << endl;
			result = false;
		}
		return result;
	};

private:
	int Container[MAX_STACK_SIZE] = {};	// 스택 컨테이너
	int StackPointer = INVALID_STACK_POINTER;
};






