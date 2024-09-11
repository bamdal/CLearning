#pragma once

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef vector<vector<int>> VA;

class BFS
{
	int NodeCount;
	VA _va;
	vector<bool> VArr;

public:

	BFS(int _cnt1) : NodeCount(_cnt1)
	{
		_va.resize(NodeCount + 1);
		VArr = vector<bool>(NodeCount + 1, false); // 방문 배열
	}

	VA& GetGraph() { return _va; }

	void F_Execute(int Start)
	{
		queue<int> myqueue;
		myqueue.push(Start);
		VArr[Start] = true;

		while (!myqueue.empty())
		{
			int now_node = myqueue.front();
			myqueue.pop();
			cout << now_node << " ";
			for (int i : _va[now_node])
			{
				if (!VArr[i])
				{
					VArr[i] = true;
					myqueue.push(i);
				}
			}
		}
	}
};