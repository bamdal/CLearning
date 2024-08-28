#pragma once

#include <iostream>

extern int iGlobalVal;	// extern : 다른 파일에서 정의된 전역 변수를 공유 하겠다

int MyMultiplyFunc(int param1, int param2);	//MyMultiplyFunc함수 선언

void MyScopeTestFunc(void);