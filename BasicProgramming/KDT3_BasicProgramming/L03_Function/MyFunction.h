#pragma once

#include <iostream>

extern int iGlobalVal;	// extern : 다른 파일에서 정의된 전역 변수를 공유 하겠다

int MyMultiplyFunc(int param1, int param2);	//MyMultiplyFunc함수 선언

int MyAddFunc(int param1, int param2 = 100);	// 디폴트 인자

void MyScopeTestFunc(void);

// 함수 오버로딩 Overloading => 함수의 signature(서명)
int MyAddFuncOver(int param1);
int MyAddFuncOver(int param1, int param2);
int MyAddFuncOver(char Init, int param1, int param2);