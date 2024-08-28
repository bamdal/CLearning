#include <iostream>
using namespace std;

int main()
{
	bool bState = true;

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

}

