// L16_SLL.cpp : 정적 라이브러리 (알고리즘 예저에 사용)


#include "pch.h"

// TODO: 라이브러리 함수의 예제입니다.

void MyTestLibFunction()
{
	cout << "__FUNCTION__" << endl;
}

void PrintVector(std::vector<int>& V)
{
	int i = 0;
	string strValue;
	for (int& it : V)
	{
		if (i++ < 10)
		{
			strValue += format("[{}]", it);
		}
		else
		{
			i = 0;
			cout << strValue << endl;
			strValue = "";
		}
	}
	cout << endl;
}