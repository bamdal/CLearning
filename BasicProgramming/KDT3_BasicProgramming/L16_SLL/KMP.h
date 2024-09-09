#pragma once

#include <string>
#include <vector>

using namespace std;

/// <summary>
/// 수많은 문자열 검색 알고리즘중 적당히 쓸만함
/// 실패 배열 생성(접두부와 접미부 비교후 -1 삽입)
/// </summary>
class CKMP
{
public:
	CKMP(const char* _source, const char* _pattern) : strSource(_source), strPattern(_pattern)
	{
		size_t PatternSize = strPattern.size();
		if (PatternSize > 0)
		{
			vFailure.resize(PatternSize);
			vFailure[0] = INVALID;
			Fail(strPattern.c_str());
		}


	}

	void Fail(const char* pat);
	int Find();

private:
	const int INVALID = -1;
	string strSource;
	string strPattern;
	vector<int> vFailure;
};




