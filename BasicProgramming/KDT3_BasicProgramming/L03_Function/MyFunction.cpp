#include "MyFunction.h"

using std::cout;
using std::endl;

int iGlobalVal = 10000;	// 전역 변수

int MyMultiplyFunc(int param1, int param2)
{
	return param1 * param2;
}

/// <summary>
/// 호출 시 param2에 인자를 넣지 않으면 디폴트 인자 100으로 정의 됨
/// </summary>
/// <param name="param1"></param>
/// <param name="param2">디폴트 인자 100</param>
/// <returns></returns>
int MyAddFunc(int param1, int param2)
{
	int iRet = param1 + param2;
	return iRet;
}

void MyScopeTestFunc(void)
{
	int iLocalVal = 300;	// 이 함수 내에서만 접근가능한 지역 변수

	cout << "iLocalVal = " << iLocalVal << endl;
	cout << "MyScopeTestFunc에서 사용 : 전역변수 iGlobalVal = " << iGlobalVal << endl;

}

int MyAddFuncOver(int param1)
{
	int iRet = param1 + 100;
	return iRet;
}

int MyAddFuncOver(int param1, int param2)
{
	int iRet = param1 + param2 + 100;
	return iRet;
}

int MyAddFuncOver(char Init, int param1, int param2)
{
	cout << "MyAddFuncOver 3param : " << Init << " : ";
	int iRet = param1 + param2 + 100;
	
	return iRet;
}

