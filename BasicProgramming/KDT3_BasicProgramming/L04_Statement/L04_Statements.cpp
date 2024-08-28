#include <iostream>
using namespace std;

int main()
{
	bool bState = false;

#pragma region L04_Statements / 조건문 ( if / else if / else)
	{
		// 참(true:1)과 거짓(false:0)에 따라 실행 흐름을 분기할 때 사용 => 0이 아닌 모든값은 참
		if (bState)
		{
			cout << "조건이 참(true)일 때 출력" << endl;
		}
		else
		{
			cout << "조건이 거짓(false)일 때 출력" << endl;
		}

		if (bState == true)
		{
			int iInputVal = 0;
			cin >> iInputVal; //사용자에게 정수값 받기
			if (iInputVal > 0)
			{
				cout << "양수를 입력 iInputVal : " << iInputVal << endl;
			}
			else if (iInputVal < 0)
			{
				cout << "음수를 입력 iInputVal : " << iInputVal << endl;

			}
			else
			{
				cout << "0을 입력 iInputVal : " << iInputVal << endl;

			}
		}
	}
#pragma endregion

#pragma region L04_Statements / 조건문 ( switch / case)
	{
		bState = true;
		if (bState)
		{
			int iInputVal = 0;
			cin >> iInputVal;

			switch (iInputVal)
			{
			case 1:
				cout << "입력한 값은 1입니다." << endl;
				break;
			case 2:
				{
					cout << "입력한 값은 2입니다." << endl;
					break;
				}
			case 3:
				{
					cout << "입력한 값은 3입니다." << endl;
				}break;
			default:
				break;
			}
		}
	}
#pragma endregion

#pragma region L04_Statements / 반복문( while / do while / for)
	{
		if (bState)
		{
			int iCount = 10;
			while (iCount > 0)
			{

				cout << "while문의 현재 iCount 값은 = " << iCount << endl;
				iCount = iCount - 1; // 값을 1씩 줄여나감
			}
			// iCount == 0
			do
			{
				// 먼저 반복문 내부의 블럭을 "한번" 처리하고 조건을 체크한다.
				cout << "do while문의 현재 iCount 값은 =" << iCount << endl;
				iCount = iCount + 1; // 값을 1씩 늘려나감
			} while (iCount < 10); // 조건이 참이면 무한 반복. 거짓이면 {} 을 빠져나감

			// 두 반복문의 차이는 조건 검사를 먼저하냐 나중에 하냐 차이
			// 의도치 않는 무한 반복 케이스가 나오지 않게 주의 !!

				// for( 초기식; 조건식; 중감식: ) 조건식이 참일때 { ) 실행 / 거짓이면 { } 실행없이 빠져나감
			for (int i = 0; i < 5; ++i)
			{
				cout << "for문 " << i + 1 << "번째 수행" << endl;

			}
			for (int i = 10; i > 0; --i)
			{
				cout << "for문 i=" << i << endl;
				if (i == 5)
				{
					cout << "break를 만나면 자동으로 블럭 탈출" << endl;
					break;
				}

			}

			for (int i = 0; i < 5; i++)
			{
				for (int j = i; j < 5; j++)
				{
					cout << 'A';
				}
				cout << endl;
			}
		}
	}

#pragma endregion

}

