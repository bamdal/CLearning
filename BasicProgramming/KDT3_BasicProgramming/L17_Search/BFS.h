#pragma once

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef vector<vector<int>> VA;

class BFS
{
	int NodeCount, EdgeCount, StartNode;
	VA _va;
	vector<bool> VArr;

public:
	BFS(int _cnt1, int _cnt2) : NodeCount(_cnt1), EdgeCount(_cnt2)
	{
		_va.resize(NodeCount + 1);
		VArr = vector<bool>(NodeCount + 1, false);	// 방문 배열
	}

	VA& GetGraph() { return _va; }
	
	int F_Excute(int node)
	{
		queue<int> myqueue;
		myqueue.push(node);
		VArr[node] = true;
		int count = 0;
		while (!myqueue.empty())
		{
			int now_node = myqueue.front();
			myqueue.pop();

			cout << now_node << " ";
			for (int i : _va[now_node])
			{
				if (!VArr[i])
				{
					count++;
					VArr[i] = true;
					myqueue.push(i);
				}
			}


		}
		return count;
	}



};