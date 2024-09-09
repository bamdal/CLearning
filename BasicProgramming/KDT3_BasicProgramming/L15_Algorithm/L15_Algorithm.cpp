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

}
