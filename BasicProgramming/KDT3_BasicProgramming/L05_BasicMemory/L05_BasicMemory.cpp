#include <iostream>
#include <bitset>
using namespace std;

void TestFunc()
{
	int iLocalVal = 0;
	static int iStaticVal = 0;

	cout << "TestFunc() 호출 : LocalVal 주소 : " << &iLocalVal << ", StaticVal 주소 : " << &iStaticVal << endl;
	cout << "TestFunc() 호출 : LocalVal 값 : " << iLocalVal << ", StaticVal 값 : " << iStaticVal << endl;

	iLocalVal++;
	iStaticVal++;

	return;
}

int iGlobalTest;	// 전역변수는 선언만 해도 0이 들어간다.

int main()
{
#pragma region L05_BasicMemory / 비트 연산자 ( AND, OR, XOR, Shift)
	{
		cout << "[ 10진수 255에 대한 각 진법별 입력 ]" << endl;

		int Bit10 = 255;  		// 10진수
		int Bit16 = 0xFF; 		// 16진수
		int Bit08 = 0377; 		// 8진수
		int Bit02 = 0b11111111; // 2진수
		if ((Bit10 == Bit16) && (Bit08 == Bit02) && (Bit10 == Bit02))
		{
			cout << "Bit10 = " << Bit10 << endl;
			cout << "Bit16 = " << hex << Bit16 << endl;
			cout << "Bit08 = " << oct << Bit08 << endl;
			cout << "Bit02 = " << bitset<8>(Bit02) << endl;

			cout << dec << Bit16 << Bit08 << Bit02 << endl;
		}
	}

	{
		cout << "[ signed와 unsingned char의 비트 구조와 음수 표현]" << endl;

		unsigned char A = 0;
		cout << "A = " << bitset<8>(A) << " : " << int(A) << endl;
		A = 255;
		cout << "A = " << bitset<8>(A) << " : " << int(A) << endl;

		signed char B = 0;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;
		B = 1;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;
		B = 2;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;
		B = 127;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;
		B = 255;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;

	}

	// 비트 연산 (~)
	// 각 자리의 bit 들을 반전 시킴(0은 1로, 1은 0으로)
	{
		// 음수 표현(2의 보수법) => 해당 양수의 모든 비트들 반전한 뒤 1을 더함
		char A = 1;
		cout << "양수 A =" << bitset<8>(A) << ":" << int(A) << endl;
		A = ~A;
		cout << "비트 A =" << bitset<8>(A) << ":" << int(A) << endl;
		A += 1;
		cout << "음수 A =" << bitset<8>(A) << ":" << int(A) << endl;
		A = 127;
		cout << "양수 A=" << bitset<8>(A) << ":" << int(A) << endl;
		A = ~A;
		cout << "비트 A = " << bitset<8>(A) << " : " << int(A) << endl;
		A += 1;
		cout << "음수A=" << bitset<8>(A) << ":" << int(A) << endl;
	}

	// 비트 AND 연산 (&)
	// 각 자리 비트를 비교해 둘 다 1이면 1 둘 중 하나가 0 이면 0
	{
		cout << "[ 비트 AND 연산자 char ]" << endl;
		// char형 값의 범위 (-128 ~ 127)
		char A = 100;	// 0110 0100
		char B = 85;	// 0101 0101
		char C = A & B;	// 0100 0100
		cout << "A = " << bitset<8>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<8>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<8>(C) << " : " << (C) << endl;
	}

	{
		cout << "[ 비트 AND 연산자 unsigned short ]" << endl;
		unsigned short A = 65280;	// 1111 1111 0000 0000
		unsigned short B = 255;		// 0000 0000 1111 1111
		unsigned short C = A & B;	// 0000 0000 0000 0000

		cout << "A = " << bitset<16>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<16>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<16>(C) << " : " << (C) << endl;

	}

	// 비트 OR 연산(|)
	// 각 자리 비트 비교후 둘다 0이면 0 둘중 하나라도 1이면 1
	{
		cout << "[ 비트 OR 연산자 char ]" << endl;

		// char형 값의 범위 (-128 ~ 127)
		char A = 100;	// 0110 0100
		char B = 85;	// 0101 0101
		char C = A | B;	// 0111 0101
		cout << "A = " << bitset<8>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<8>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<8>(C) << " : " << (C) << endl;
	}
	{
		cout << "[ 비트 OR 연산자 unsigned short ]" << endl;
		unsigned short A = 65280;	// 1111 1111 0000 0000
		unsigned short B = 255;		// 0000 0000 1111 1111
		unsigned short C = A | B;	// 1111 1111 1111 1111

		cout << "A = " << bitset<16>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<16>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<16>(C) << " : " << (C) << endl;

	}

	// 비트 XOR 연산 ( ^ )
	// 각 자리의 bit들을 비교해 둘이 같을 경우 0, 서로 다를 경우 1
	{
		cout << "[ 비트 XOR 연산자 char ]" << endl;

		// char형 값의 범위 (-128 ~ 127)
		char A = 100;	// 0110 0100
		char B = 85;	// 0101 0101
		char C = A ^ B;	// 0011 0001
		cout << "A = " << bitset<8>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<8>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<8>(C) << " : " << (C) << endl;
	}
	{
		cout << "[ 비트 XOR 연산자 unsigned short ]" << endl;
		unsigned short A = 65280;	// 1111 1111 0000 0000
		unsigned short B = 255;		// 0000 0000 1111 1111
		unsigned short C = A ^ B;	// 1111 1111 1111 1111

		cout << "A = " << bitset<16>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<16>(B) << " : " << (B) << endl;
		cout << "C = " << bitset<16>(C) << " : " << (C) << endl;

	}

	// Shift 연산 ( << | >> )
	{
		cout << "[ Shift 연산자 char 왼쪽(<<) ]" << endl;

		char A = 1;			// 00000001
		char B = A << 7;	// 10000000 => A의 MSB쪽 비트들은 밀려서 버려짐, LSB 자리에는 신규로 '0'이 들어옴
		cout << "A = " << bitset<8>(A) << " : " << int(A) << endl;
		cout << "B = " << bitset<8>(B) << " : " << int(B) << endl;
	}

	{
		cout << "[ Shift 연산자 unsigned char 오른쪽(>>) ]" << endl;
		unsigned short A = 65535;	// 1111 1111 1111 1111
		unsigned short B = A >> 3;		// 0001 1111 1111 1111 => A의 LSB쪽 비트들은 밀려서 버려짐, MSB 자리에는 신규로 '0'이 들어옴

		cout << "A = " << bitset<16>(A) << " : " << (A) << endl;
		cout << "B = " << bitset<16>(B) << " : " << (B) << endl;

	}

	{
		// int형 변수의 << 연산 출력
		cout << "[ int형 bit 이동(<<) ]" << endl;
		int A = 1;
		for (int i = 0; i < 32; i++)
		{
			cout << "A = " << bitset<32>(A) << " : " << int(A) << endl;
			A = A << 1;
		}

	}
#pragma endregion

#pragma region L05_BasicMemory / Local, Static, Global 변수
	{
		cout << "[ 지역변수, 정적변수, 전역변수 ]" << endl;
		int i = 0;
		for (;;)
		{
			if(i++<5)
			{
				TestFunc();
			}
			else
			{
				break;
			}
		}
		cout << "전역변수 : &iGlobalTest = " << &iGlobalTest << " iGlobalTest = " << iGlobalTest << endl;
		
	}
#pragma endregion

#pragma region L05_BasicMemory / 형변환 1
	// 암시적 형변환 : 컴파일러가 표현식을 규약에 따라 자동으로 Casting 하는 것
	{
		// 데이터의 유실
		short sA = 0x0401;
		cout << "short sA값 = " << bitset<16>(sA) << " : " << sA << endl;
		char cB = sA; // warning C4244 '초기화 중': 'short' 에서 'char'로 변환 과정에서 데이터 손실이 있을수 있음
		cout << "char cB값 = " << bitset<8>(cB) << " : " << (int)cB << endl;

		int iC = -36864;
		cout << "int iC값 = " << bitset<32>(iC) << " : " << iC << endl;
		sA = iC; // 경고도 안함
		cout << "short sA값 = " << bitset<16>(sA) << " : " << sA << endl;
	}

	// 명시적 형변환 : 개발자가 표현식을 의도적으로 직접 Casting 하는 것
	{
		int iA = 100, iB = 6;

		float fAvg = iA / iB;		// ( warning C4244) 정수값의 나눗셈 후 암시적 형변환 => 소수부 유실
		cout << "1) fAvg 값 = " << fAvg << endl;
		fAvg = (float)iA / iB;		// 분자를 명시적 Casting
		cout << "1) fAvg 값 = " << fAvg << endl;
		fAvg = iA / (float)iB;		// 분모를 명시적 Casting
		cout << "1) fAvg 값 = " << fAvg << endl;
		fAvg = (float)(iA / iB);	// 이미 정수값으로 데이터 유실된 상태에서 명시적 Casting
		cout << "1) fAvg 값 = " << fAvg << endl;

	}
#pragma endregion


}
