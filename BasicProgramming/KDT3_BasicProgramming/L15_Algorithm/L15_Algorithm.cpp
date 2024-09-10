// L15_Algorithm.cpp : 알고리즘(문자열, 정렬, 탐색, 그래프등)
#include "framework.h"
#include <iostream>
#include <random>
#include <format>

using namespace std;
int main()
{
#pragma region 난수(random number)
		std::random_device RD;			// 특수 하드웨어 필요(여기선 소프트웨어적 알고리즘으로 동작)
		double Entropy = RD.entropy();	// 난수의 성능은 Entropy(무질서도)로 측정 -> 2^32 내에 균일하게 분포

		std::mt19937 Gen(RD());	// 난수를 생성하기 위한 엔진(MSVC 기본)
		std::uniform_int_distribution<int> Dist(0, 999);	// 분포지정
		int randomValue = Dist(Gen);
		bool bExit = true;

	{


		if (!bExit)
		{
			string strRandom;
			// 0~999 출력
			for (int i = 0; i < 10; i++)
			{

				for (int j = 0; j < 10; j++)
				{
					randomValue = Dist(Gen);
					strRandom += format("[{}] \t", randomValue);
				}
				strRandom += format("\n");
			}
			cout << strRandom.c_str() << endl;
		}


		int RepeatCount = 1000;	// 반복횟수
		// 일반 확률(분포 수렴[convergence in distribution])
		while (!bExit)
		{
			cout << "명령값을 입력하세요 1) 수행 | 그외 Exit" << endl;

			int userInput = 0;
			cin >> userInput;

			if (userInput == 1)	// 수행
			{
				bool bFind = false;
				for (int i = 0; i < RepeatCount; i++)
				{
					randomValue = Dist(Gen);
					if (randomValue == 666)	// 0.1%
					{
						cout << format("[{}번째에 [{}]이 나왔습니다]\n", i, randomValue);
						bFind = true;
						break;
					}
				}

				if (!bFind)
				{
					cout << "1000번돌려도 666은 나오지 않음" << endl;
				}

			}
			else
			{
				bExit = false;
				
			}

		}


	
	}

	// 확정 확률(수행 횟수내 반드시 나오거나 거의 유사하게 나옴) | (확실한 수렴[sure distribution]) => 실무에선 더욱 정교
	{
		int RepeatCount = 1000;	// 반복횟수
		// 일반 확률(분포 수렴[convergence in distribution])
		while (!bExit)
		{
			cout << "명령값을 입력하세요 1) 수행 | 그외 Exit" << endl;

			int userInput = 0;
			cin >> userInput;

			if (userInput == 1)	// 수행
			{
				bool bFind = false;
				for (int i = 0; i < RepeatCount; i++)
				{
					randomValue = Dist(Gen);
					if (randomValue == 666)	// 0.1%
					{
						cout << format("[{}번째에 [{}]이 나왔습니다]\n", i, randomValue);
						bFind = true;
						break;
					}
				}

				if (!bFind)
				{
					cout << format("{}번돌려도 666은 나오지 않음",RepeatCount) << endl;
					RepeatCount += 300;
				}

			}
			else
			{
				bExit = false;

			}

		}
	}
#pragma endregion

		MyTestLibFunction();
#pragma region 문자열 검색 / KMP(Knuth-Morris-Pratt) Algorithm
		{
			// 문자열 검색 => 소스 문자열과 특정패턴 문자열이 있을 때 소스에 그 패턴이 있냐?
			std::string strSource = "HelloWorld!";
			std::string strPattern = "or";

			CKMP Obj(strSource.c_str(), strPattern.c_str());	// 라이브러리의 CKMP
			int Result = Obj.Find();
			Obj.Fail(strPattern.c_str());
			if (Result == -1)
			{
				cout << "패턴이 존재 하지 않음\n";

			}
			else
			{
				cout << format("인덱스 [{}]에 패턴이 존재한다\n", Result);
			}
		}
#pragma endregion

#pragma region 정렬
		{
			// 1) 버블 정렬(bubble sort) : 두 인접한 데이터의 크기를 비교해 위치를 swap 하며 정렬
			// => 수열을 제공 => swap이 어디서 발생하냐


			int N = 100;
			vector<int> V(N, 777); // resize(N) + 777로 초기화
			for (int i = 0; i < 100; i++)
			{

				V[i] = Dist(Gen); // 랜덤값으로 수정
			}

			cout << "[ 버블정렬 이전 ]" << endl;
			PrintVector(V);

			for (int i = 0; i < N - 1; i++)
			{
				for (int y = 0; y < N - 1 - i; y++)
				{
					if (V[y] > V[y + 1]) // swap 연산 체크
					{

						int T = V[y];
						V[y] = V[y + 1];
						V[y + 1] = T;
					}

				}
			}


			cout << "[ 버블정렬 이후 ]" << endl;
			PrintVector(V);

			for (int i = 0; i < 100; i++)
			{

				V[i] = Dist(Gen); // 랜덤값으로 수정
			}

			cout << "[삽입정렬 이전]" << endl;

			PrintVector(V);
			int Key = 0, y = 0;
			for (int i = 1; i < N; i++)	// 인덱스 0번은 이미 정렬된것으로 불 수 있다
			{
				Key = V[i];	// 현재 삽입될 숫자인 i 번째 정수를 key변수로 복사
				// 현재 정렬된 배열은 i-1까지 i-1번쨰부터 역순으로 조사

				// [y]값은 음수가 아니고 Key값보다 정렬된 배열에 값이 크면 [y]번째를 [y-1]번째로 이동
				for (y = i - 1; y >= 0 && V[y] > Key; y--)
				{
					V[y + 1] = V[y];	//레코드의 오른쪽으로 이동
				}
				V[y + 1] = Key;
			}

			cout << "[삽입정렬 이후]" << endl;
			PrintVector(V);
		}

		// 3) 퀵정렬(quick sort)	: pivot(기준)값을 선정해 해당 값보다 작은 데이터와 큰 데이터로 분류하는 것을 반복(재귀호출)하여 정렬
		// 구현 복잡, 시간 복잡도는 평균 O(nlogn) 최악 O(n^2)
		{
			int N = 100;
			vector<int> V(N, 777); // resize(N) + 777로 초기화
			for (int i = 0; i < 100; i++)
			{

				V[i] = Dist(Gen); // 랜덤값으로 수정
			}


			cout << "[ 퀵정렬 이전 ]" << endl;
			PrintVector(V);

			QuickSort(V, 0, N - 1);

			cout << "[ 퀵정렬 이후 ]" << endl;
			PrintVector(V);

		}
		// 4) 힙 정렬(Heap sort) : 완전 이진트리를 베이스로 힘 자료구조를 기반한 정렬
		// min,max 값을 쉽게 추출할 수 있다.
		// 구현은 복잡, 시간복잡도 최선,평균,최악 모두 O(log n), 공간 복잡도 O(n)
		{

			int N = 101;
			vector<int> V(N, 0); // resize(N) + 777로 초기화
			for (int i = 1; i < 101; i++)
			{

				V[i] = Dist(Gen); // 랜덤값으로 수정
			}
			cout << "[ 힙정렬 이전 ]" << endl;
			PrintVector(V);

			CHeapSort Obj(V);
			Obj.HeapSort();

			cout << "[ 힙정렬 이후 ]" << endl;
			PrintVector(V);

		}
#pragma endregion


}
