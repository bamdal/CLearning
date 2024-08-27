// L01_StandardIO : C/C++의 표준 입출력( Standard Input Output )
// CLI( Command Line Interface ) 환경에서 사용.

#include <stdio.h>		// C
#include <iostream>		// C++

int main()
{
	// 정수형 변수 선언, 초기화
	int iNum1 = 0; 
	int iNum2 = 0;

#pragma region L01_StandardIO / C++ 스타일
	{
		// std::cout ==> ""안의 문자열을 출력
		// std::cin   ==> 유저에게 데이터를 입력받아 변수에 저장

		std::cout << "=C++ Style=" << std::endl;
		std::cout << "input Num1 : ";
		std::cin >> iNum1;	// 사용자에게 정수를 입력받아 저장

		std::cout << "Num1 = " << iNum1 << std::endl;

		std::cout << "input Num2 : ";
		std::cin >> iNum2;	

		std::cout << "Num2 = " << iNum2 << std::endl;
		std::cout << "Num1 = " << iNum1 << ", " << "Num2 = " << iNum2 << std::endl;

		// 입력한 두수의 덧셈을 출력
		std::cout << "Num1 + Num2 = " << iNum1 + iNum2 << std::endl;
		// 입력한 두수의 뺄셈을 출력
		std::cout << "Num1 - Num2 = " << iNum1 - iNum2 << std::endl;
		// 입력한 두수의 곱셈을 출력
		std::cout << "Num1 * Num2 = " << iNum1 * iNum2 << std::endl;
		// 입력한 두수의 몫을 출력
		std::cout << "Num1 / Num2 = " << iNum1 / iNum2 << std::endl;
		// 입력한 두수의 나머지를 출력
		std::cout << "Num1 % Num2 = " << iNum1 % iNum2 << std::endl;

	}
#pragma endregion

#pragma region L01_StandardIO / C 스타일
	{
		printf("= C Style = \n");	// "" 안에 문자열 출력
		printf("input Num : ");
		scanf_s("%d", &iNum1);	// 유저에게 정수를 입력받아 iNum1에 저장
		// scanf는 C++ 14 이상에서 deprecated 됐다.
		
		printf("input Num2 : ");
		scanf_s("%d", &iNum2);	// 유저에게 정수를 입력받아 iNum1에 저장

		printf("Num1 = %d, Num2 = %d\n", iNum1, iNum2);

		//덧셈출력
		printf("Num1 + Num2 = %d\n", iNum1 + iNum2);
		//뺄셈출력
		printf("Num1 - Num2 = %d\n", iNum1 - iNum2);
		//곱셈출력
		printf("Num1 * Num2 = %d\n", iNum1 * iNum2);
		//나눗셈(몫)출력
		printf("Num1 / Num2 = %d\n", iNum1 / iNum2);
		//나눗셈(나머지)출력
		printf("Num1 %% Num2 = %d\n", iNum1 % iNum2);

		printf("\a");	// 이스케이프 시퀀스(경고음)

	}

#pragma endregion

}

