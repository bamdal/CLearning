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
			strValue += format("[{}] \t", it);
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

void swap(vector<int>& A, int x, int y)
{
	int T = A[x];
	A[x] = A[y];
	A[y] = T;
}

int QuickSort(vector<int>& A, int start, int end)
{
	if (start >= end)
	{
		return 0;
	}

	int pivot = start;	// 기준값
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (i<= end &&(A[i] <= A[pivot]))	// 키 값보다 큰 값을 만날때까지 오른쪽으로 이동
		{
			i++;
		}
		while (i > start && A[j] >= A[pivot] && j > start)	// 키 값보다 작은 값을 만날때까지 왼쪽으로 이동
		{
			j--;
		}
		if (i > j)
		{
			swap(A, j, pivot);
		}
		else
		{
			swap(A, j, i);
		}

		//재귀 호출
		QuickSort(A, start, j - 1);
		QuickSort(A, j+1, end);
	}


	return 0;
}

