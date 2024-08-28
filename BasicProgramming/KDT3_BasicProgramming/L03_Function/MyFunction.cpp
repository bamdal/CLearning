#include "MyFunction.h"

using std::cout;
using std::endl;

int iGlobalVal = 10000;	// 전역 변수

int MyMultiplyFunc(int param1, int param2)
{
	return param1 * param2;
}

void MyScopeTestFunc(void)
{
	int iLocalVal = 300;	// 이 함수 내에서만 접근가능한 지역 변수

	cout << "iLocalVal = " << iLocalVal << endl;
	cout << "MyScopeTestFunc에서 사용 : 전역변수 iGlobalVal = " << iGlobalVal << endl;

}