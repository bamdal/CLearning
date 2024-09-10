#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include <iostream>
#include <format>
using namespace std;


#include "KMP.h"

void MyTestLibFunction();
void PrintVector(std::vector<int>& V);
void swap(vector<int>& A, int x, int y);

int QuickSort(vector<int>& A, int start, int end);

class CHeapSort
{
	int Count;
	vector<int>& V;

public:
	CHeapSort(vector<int>& _v) : V(_v)
	{
		Count = (int)(V.size());
		if (Count > 0)
		{
			for (int i = Count / 2; i > 0; i--)
			{
				Heapify(i);
			}
		}

	}

	void Heapify(int i)
	{
		int cur = 2 * i;
		if (cur < Count - 1 && V[cur] < V[cur + 1])
		{
			cur++;
		}
		if (V[i] < V[cur])
		{
			swap(V, i, cur);
			if (cur <= Count / 2)
			{
				Heapify(cur);
			}
		}
	}

	// 외부에서 객체선언해서 이 함수 콜하면 자동 힙정렬 되게한다
	void HeapSort()
	{
		for (int i = Count - 1; i > 0; i--)
		{
			Sort(i);
		}
	}

	void Sort(int i)
	{
		swap(V, 1, i);

		int root = 1;
		int cur = 2;
		while (cur / 2 < i)
		{
			cur = 2 * root;
			if (cur < i - 1 && V[cur] < V[cur + 1])
			{
				cur++;

			}
			if (cur < i && V[root] < V[cur])
			{
				swap(V, root, cur);

			}
			root = cur;
		}
	}
};