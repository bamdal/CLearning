// L17_Search.cpp : 탐색

#include <iostream>
#include "DFS.h"
#include "BFS.h"

using namespace std;


int main()
{
#pragma region DFS (depth - first search)
	{
		bool go = true;
		if (!go)
		{
			int NodeCount, EdgeCount;
			cout << "노드의 개수 입력 : ";
			cin >> NodeCount;
			cout << "간선의 개수 입력 : ";
			cin >> EdgeCount;

			DFS ObjDFS(NodeCount, EdgeCount);
			for (int i = 0;  i < EdgeCount; i++)
			{
				cout << "간선을 이루는 두 노드 입력 : " << endl;
				int N1, N2;
				cin >> N1 >> N2;	// Vi, Vj
				ObjDFS.GetGraph()[N1].push_back(N2);
				ObjDFS.GetGraph()[N1].push_back(N1);
			}

			int cnt = ObjDFS.F_Execute();
			cout << "DFS의 연결요소 수(그래프가 하나로 이뤄져 있는지)는 : " << cnt << "\n";
		}
	}
#pragma endregion

#pragma region BFS (breadth - first search)
	{
		bool go = true;
		if (go)
		{
			int NodeCount, EdgeCount,Start;
			cout << "노드의 개수 입력 : ";
			cin >> NodeCount;
			cout << "간선의 개수 입력 : ";
			cin >> EdgeCount;
			cout << "시작지점 : ";
			cin >> Start;

			BFS ObjBFS(NodeCount, EdgeCount);
			for (int i = 0; i < EdgeCount; i++)
			{
				cout << "간선을 이루는 두 노드 입력 : " << endl;
				int N1, N2;
				cin >> N1 >> N2;	// Vi, Vj
				ObjBFS.GetGraph()[N1].push_back(N2);
				ObjBFS.GetGraph()[N1].push_back(N1);
			}

			int cnt = ObjBFS.F_Excute(Start);
			cout << "BFS의 연결요소 수(그래프가 하나로 이뤄져 있는지)는 : " << cnt << "\n";
		}

	}
#pragma endregion

}
