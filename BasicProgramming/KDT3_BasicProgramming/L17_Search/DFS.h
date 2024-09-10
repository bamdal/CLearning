#pragma once
// 깊이우선탐색
#include <vector>

using namespace std;

typedef vector<vector<int>> VA;

class DFS
{
	int NodeCount, EdgeCount;
	VA _va;
	vector<bool> VArr;

public:
	DFS(int _cnt1, int _cnt2) : NodeCount(_cnt1), EdgeCount(_cnt2)
	{
		_va.resize(NodeCount + 1);
		VArr = vector<bool>(NodeCount + 1, false);	// 방문 배열
	}

	VA& GetGraph() { return _va; }

	void F_DFS(int v)
	{
		if (VArr[v])
		{
			return;
		}
		VArr[v] = true;
		for (int i : _va[v])
		{
			if (VArr[i] == false)
			{
				F_DFS(i);
			}
		}
	}
	int F_Execute()
	{
		int count = 0;
		for (int i = 1; i < NodeCount + 1; i++)
		{
			if (!VArr[i])	//방문하지 않은 노드가 없을 때까지 반복
			{
				count++;
				F_DFS(i);
			}
		}
		return count;

	}

};