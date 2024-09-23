#include <iostream>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <string>

using namespace std;

int main()
{
#pragma region L02_Variable / 변수의 선언, 정의, 대입 
	{
		std::cout << "== Variable ==" << std::endl;

		int iA; // 선언만 하면 iA는 쓰레기 값만 들어감 => 이 변수를 그냥 사용하면 컴파일 에러가 뜸
		iA = 0;
		std::cout << "iA : " << iA << std::endl;

		// 변수의 선언 + 정의(definition) => 값을 넣어서 변수를 초기화 시켜주는 것
		int iB = 100; // 변수는 항상 초기화 해서 습관화 할것
		std::cout << "iB : " << iB << std::endl;
	}
#pragma endregion

#pragma region L02_Variable / 상수, 리터럴
	{
		std::cout << "== Constant ==" << std::endl;
		//const int iVal;	// 선언만 하면 컴파일 오류
		const int iVal = 10;	// 상수 - 변하지 않음 선언과 정의를 같이해야함
		//int const iVal = 10;	// const는 자료형 앞,뒤 어디든 있어도 된다
		//iVal = 100;	// 상수화된 변수에는 값을 대입할 수 없다.
		std::cout << "iVal : " << iVal << std::endl;

		int iNum = 30;
		std::cout << "Val + Num = " << iVal + iNum + 10 << std::endl;

		// 이 예시에서 10, 100 => 리터럴( literals ) 이라함.

		char szString[] = "Hello";        // 문자열 리터럴
		const char* ptr = szString;
		//ptr[0] = 'Q'; // 컴파일 에러
		char szString2[] = "World!";
		char* const ptr2 = szString2;
		//ptr2 = szString; // 컴파일 에러
		const char* const ptr3 = "Headcooler";
		//ptr3 = szString; // 컴파일 에러
		//ptr3[0] = 'K'; // 컴파일 에러

		int a = 10;
		const int num1 = 100; // 컴파일 타임 상수( compile-time constant )
		const int num2 = a; // 런타임 상수( runtime constant )
		//num2 = 1000;
		_CONSTEXPR20 int num3 = 50; // 컴파일 타임 상수 ( 엄격 ) => 런타임 상수를 허용하지 않는다.
		//num3 = 100; // 컴파일 에러

	}
#pragma endregion

#pragma region L02_Variable / 자료형( data type ) / bool형
	{
		std::cout << "== data type ==" << std::endl;
		std::cout << "== (1) bool형 ==" << std::endl;

		
		bool bVal1 = true;	// 정수 1 참(true)
		bool bVal2 = false;	// 정수 0 거짓(false)
		// true, false도 리터럴이다.

		// sizeof(자료형)는 해당 자료형이 차지하는 메모리 크기를 반환하는 연산자
		int ibool_size = sizeof(bool);

		bVal1 = 123;
		bVal1 = 0;
		bVal1 = 0.1;
		// bool형은 0이 아니면 모두 참이다

		std::cout << bVal1 << "," << bVal2 << std::endl;
		std::cout << "bool size : " << ibool_size << std::endl;
		
	}
#pragma endregion

#pragma region L02_variable / 자료형 ( data type ) / 정수형
	{
		std::cout << "== (2) 정수형 ==" << std::endl;
		// 정수 : 음의 정수(-1,-2,...), 0, 양의 정수(1,2,...)
		// signed : 정수(기본), unsigned : 양의 정수 => 표현 범위가 2배

		// 2바이트 정수형 ( 기본적으로 signed )
		short sData = -100;
		//signed short sData = -100;	//위와 같다

		std::cout << "short 값 : " << sData << " / short size : " << sizeof(short) << " bytes" << std::endl;
		unsigned short usData = 100;	// 양의 정수만 사용가능
		//unsigned short usData = -100;	// 컴파일은 되지만 비정상적인 값이 들어감 / 메모리 시간에 overflow와 underflow발생

		std::cout << "unsigned short 값 : " << usData << " / unsigned short size : " << sizeof(unsigned short) << " bytes" << std::endl;

		// 4바이트 정수형( 기본적으로 signed )
		int iData = -1234567891;
		std::cout << "int 값 : " << iData << " / int size : " << sizeof(int) << " bytes" << std::endl;
		unsigned int uiData = 3456789123;
		std::cout << "unsigned int 값 : " << uiData << " / unsigned int size : " << sizeof(unsigned int) << " bytes" << std::endl;
		
		// 4바이트 정수형( 기본적으로 signed )
		long lData = -1234567891;
		std::cout << "long 값 : " << lData << " / long size : " << sizeof(long) << " bytes" << std::endl;
		unsigned long ulData = 3456789123;
		std::cout << "unsigned long 값 : " << ulData << " / unsigned long size : " << sizeof(unsigned long) << " bytes" << std::endl;
		
		// 8바이트 정수형( 기본적으로 signed )
		long long llData = -1234567891234567891;
		std::cout << "long long 값 : " << llData << " / long long size : " << sizeof(long long) << " bytes" << std::endl;
		unsigned long long ullData = 3456789123456789123;
		std::cout << "unsigned long long 값 : " << ullData << " / unsigned long long size : " << sizeof(unsigned long long) << " bytes" << std::endl;

		// 기타 MS 전용 정수형
		std::cout << "MS __int8 : "  << sizeof(__int8) << " bytes" << std::endl;
		std::cout << "MS __int16 : " << sizeof(__int16) << " bytes" << std::endl;
		std::cout << "MS __int32 : " << sizeof(__int32) << " bytes" << std::endl;
		std::cout << "MS __int64 : " << sizeof(__int64) << " bytes" << std::endl;
	}	   
#pragma endregion

#pragma region L02_Variable / 자료형( data type ) / 실수형
	{
		std::cout << " == (3) 실수형 ==" << std::endl;
		// 실수형은 signed / unsigned가 없음

		// 4바이트 실수형( 단정도 : 유효자릿수 7)
		float fData = 3.14f; // float형은 실수 끝에 f를 붙임
		std::cout << "float 값 : " << fData << " / float size : " << sizeof(float) << " bytes" << std::endl;
		fData = 3.1415926535f; 
		std::cout << "float 값 : " << fData << " / float size : " << sizeof(float) << " bytes" << std::endl;

		// 8바이트 실수형( 배정도 : 유효자릿수 16 )
		double dData = 3.14159265358979;
		std::cout << "double 값 : " << dData << " / double size : " << sizeof(double) << " bytes" << std::endl;
		std::cout << "double 값 정밀도 조정 " << std::setprecision(std::numeric_limits<double>::digits10+1) << dData  << std::endl;

		// 부동 소수점 주의
		double dValue = 0;
		dValue += 0.1;
		dValue += 0.1;
		dValue += 0.1;
		dValue -= 0.3;
		if (dValue == 0)
		{
			std::cout << "dvalue == 0 " << dValue << std::endl;
		}
		else
		{
			std::cout << "dvalue != 0 " << dValue << std::endl;
		}
	}

#pragma endregion

#pragma region L02_Variable / 자료형( data type ) / 문자형
	{
		std::cout << "== (4) 문자형 ==" << std::endl;

		// char : 단일문자(아스키코드 : 7bit) 저장용 1Byte 자료형
		// signed char = -128~127 까지 / unsigned char : 0 ~ 255 까지

		char cVal = 'A';
		std::cout << "cVal = " << cVal << std::endl;


		// unsigned char ucVal = 240; // 아스키코드에 해당 문자가 없어 깨진 문자가 출력됨
		// std::cout << "ucVal = " << ucVal << std::endl;

		// wchar_t : 단일 문자( 유니코드: 16비트 ) 저장용 2Byte 자료형
		_setmode(_fileno(stdout), _O_U16TEXT); // 원도우 CL에서 유니코드 출력 모드 설정
		wchar_t W1 = L'가', W2 = L'나', W3 = L'다'; // 한글
		std::wcout << "W1 W2 W3 = " << W1 << W2 << W3 << std::endl;
		wchar_t W4 = L'好', W5 = L'╰(*°▽°*)╯', W6 = L'№', W7 = L'φ(゜▽゜*)♪'; // 한자, 일본어, 러시아어, 아랍어
		std::wcout << "W4 W5 W6 W7 = " << W4 << W5 << W6 << W7 << std::endl;
	}
#pragma endregion


}
