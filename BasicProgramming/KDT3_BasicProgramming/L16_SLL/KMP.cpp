#include "pch.h"

void CKMP::Fail(const char* pat)
{
	int Findex = 0;
	size_t Num = vFailure.size();
	for (int i = 1; i < Num; i++)
	{
		Findex = vFailure[i - 1];

		// 일치할 때까지 순회
		while ((pat[i] != pat[Findex + 1]) && (Findex >= 0))
		{
			Findex = vFailure[Findex];
		}

		if (pat[i] == pat[Findex + 1])	// 패턴이 나오면
		{
			vFailure[i] = Findex + 1;
		}
		else
		{
			vFailure[i] = INVALID;	// 일치 하지 않음
		}
	}
}

int CKMP::Find()
{

	size_t s = 0, p = 0;	// 소스 인덱스, 패턴 인덱스

	size_t SourceLen = strSource.length();
	size_t PatternLen = strPattern.length();

	while (s < SourceLen && p < PatternLen)
	{
		if (strSource[s] == strPattern[p])	// 소스와 패턴이 같다면
		{
			s++;	// 소스 인덱스 한글자 뒤로
			p++;	// 패턴 인덱스 한글자 뒤로
		}
		else if (p == 0)	// 패턴의 시작 글자 부터 다르면
		{
			s++;	// 소스 인덱스 한글자 뒤로
		}
		else // 같은 부분이 있다면
		{
			p = vFailure[p - 1] + 1;	// vFailure 배열 값 이용
		}
	}


	return static_cast<int>(p == PatternLen ? s = s-PatternLen : INVALID);
}

