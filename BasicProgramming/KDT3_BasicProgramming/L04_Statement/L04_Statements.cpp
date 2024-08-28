#include <iostream>
#include <iomanip>
using namespace std;

int Test()
{
	cout << "Test() 함수 콜" << endl;
	return 1;
}

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
		//bState = true;
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
		//bState = true;
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

#pragma region L04_Statements / 연산자, 표현식, 문자(구문)
	{
		// 사칙연산 ( +, -, *, /, % ) => C/C++ 몫(/), 나머지(%) 구분
		int X = 4 + 2;
		int Y = 12 - 2;
		cout << "X = " << X << "Y = " << Y << endl;

		if (X != 0)
		{
			int Z = Y / X;
			cout << "Y / X (몫) = " << Z << endl;
			Z = Y % X;
			cout << "Y % X (나머지) = " << Z << endl;

		}
		
		// 단항 연산자 표현식
		// 1) 부호 연산자
		cout << "\n== 1) 부호 연산자 =="  << endl;
		X = -1;
		Y = -X;
		cout << "X = " << X << "Y = " << Y << endl;
		Y = +X;
		cout << "X = " << X << "Y = " << Y << endl;

		// 2) 증감 연산자(선행 후행)
		cout << "\n== 2) 증감 연산자 ==" << endl;

		// 선행
		X = 0;
		Y = 0;
		cout << "선행 X = " << ++X << endl;	
		cout << "선행 Y = " << --Y << endl;

		// 후행
		X = 0;
		Y = 0;
		cout << "후행 X = " << X++ << endl;	
		cout << "후행 Y = " << Y-- << endl;

		// 3) 형변형 연산자
		cout << "\n== 3) 형변형 연산자 ==" << endl;
		X = 10; Y = 3;
		double Z = (double)X / Y;
		cout << "Z = " << std::setprecision(std::numeric_limits<double>::digits10 + 1) << Z << endl;

		// 4) sizeof() 연산자
		cout << "\n== 4) sizeof() 연산자 ==" << endl;
		cout << "X 크기 = " << sizeof(X) << "Y 크기 = " << sizeof(Y) << endl;

		// 5) 논리 NOT
		cout << "\n== 5) 논리 NOT ==" << endl;
		bool bCheck = false;
		if (!bCheck == true)
		{
			cout << "bCheck = " << bCheck << "!bCheck = " << !bCheck << endl;
		}

		// 이항 연산자 표현식
		// 1) 산술 연산자 ( 대임, 사칙연산 )
		X = 0; Y = 0;

		// 2) 관계 연산자
		if (X == Y)
		{
			cout << "X == Y : " << (X == Y++) << endl;
		}

		if (X != Y)
		{
			cout << "X != Y : " << (X != Y) << endl;
		}
		if (X < Y)
		{
			cout << "X < Y : " << (X < Y) << endl;
		}

		X = 10;
		if (X > Y)
		{
			cout << "X > Y : " << (X > Y) << endl;
		}
		// 3) 논리 연산자 ( 0 : false, 0을 제외한 모든값 : true )
		X = -123; Y = 2930192;
		if (X && Y) // 둘 다 참일 때 ture
		{
			cout << "X && Y =" << (X && Y) << endl;
		}
		X = 0;

		if (X && Y) 
		{
			cout << "1) X && Y = " << (X && Y) << endl;
		}
		else
		{
			cout << "2) X && Y = " << (X && Y) << endl;
		}

		if (X || Y) // 둘중 하나라도 ture
		{
			cout << "1) X || Y = " << (X || Y) << endl;
		}
		else
		{
			cout << "2) X || Y = " << (X || Y) << endl;

		}

		X = 1, Y = 0, Z = 0;
		if(X || Test())	// X가 참이므로 Test()는 확인안함
		{
			cout << "Z = " << Z << endl;
		}

		// 삼항 연산자 표현식 ( 조건식 ? 참 : 거짓 )
		X = 5; Y = 4; Z = 0;
		Z = X > Y ? 10 : -10;
		cout << "Z = " << Z << endl;

		// 연산자 우선순위
		// 정상적인 회사는 ()로 묶고 구문을 분할하여 읽기 좋은 코드로 작성
	}
#pragma endregion


}

