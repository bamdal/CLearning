#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include <iostream>
#include <format>
using namespace std;


#include "KMP.h"

void MyTestLibFunction();
void PrintVector(std::vector<int>& V);