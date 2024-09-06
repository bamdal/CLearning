// L14_Contanier.cpp : STL 컨테이너

#include <iostream>
#include <vector>

using namespace std;

bool ReturnTrue()
{
	return true;
}

int main()
{
#pragma region auto : 타입 추론 (type deduction) / decitype : 타입 추론
	{
		// 타입 추론 : 컴파일러가 타입을 추론해주는 기능 -> 변수 선언, 초기화 시 
		// 타입 추출 : 함수의 반환값 레퍼런스(&), 상수(const)도 정확하게 추론
		// 무분별하게 사용시 컴파일 시간이 살짝 늘어나긴 한다 => 고민할 수준은 아님Ⅰ
		int a = 10;
		auto aa = 10;			// 정수형 리터럴은 기본적으로 int로 추론
		auto Double = 3.0;		// 실수 리터럴은 double
		auto Float = 3.5f;		// 명시적으로 f를 쓰면 flaot로 추론


		auto var1{ 10 };
		auto var2 = 10;

		bool bRet = ReturnTrue();
		auto bRet2 = ReturnTrue();

		int i = 100;
		int* intPtr = &i;
		auto autoPtr = &i;
		auto* atPtr = &i;
		auto intAuto = i;
		auto& refIntAuto = i;
	}
#pragma endregion

#pragma region Vector(벡터 : 동적 배열)

	// [vector] (TArray : Unreal vector)
	// 원소를 저장하고 각 원소에 임의 접근(random access)이 가능
	// 배열이니까 원소를 메모리 공간에 연속적으로 저장
	// 동적 배열이기에 저장된 원소 수에 따라 크기가 자동으로 증감한다.
	// 마지막(끝)에 원소를 추가하거나 삭제하는 연산을 매우 빠르게 처리(시간복잡도 O(1))
	// 원소가 추가될 때 컨테이너가 부족한 경우 메모리를 늘려야 하기 때문에 (공간복잡도 O(N))
	// (주의!!) 끝이 아닌 공간에 원소를 추가/삭제시 느릴 수 밖에 없다. >> 관련 원소들을 한칸씩 이동시켜야 하니까(O(N))
	// 모든 원소를 조회(random access)하는 경우 걸리는 시간은 배열처럼 상수 시간 소비 -> 아주 빠르다
	// 일반적으로 원소의 개수가 적은 경우 다른 컨테이터보다 vector가 더 빠르다
	{
		cout << "[STL Vector : 동적배열]" << endl;

		std::vector<int> V1{ 5,3,4 };
		std::vector V2{ 5,3,4 };
		std::vector V{ 1.5,3.5,4.4 };

		std::vector<int> V3;	// 타입 추론은 해놔야 선언만 하고 끝낼수 있음

		V3.push_back(11);
		V3.push_back(22);
		V3.push_back(33);

		int i = 0;

	}
	{
		// 콘텐츠 개발시 대략적으로(또는 명확하게)size를 예상할 수 잇는 경우 반드시
		// reserve: capacity(용량)는 *1.5배씩 사이즈가 계속 늘어난다
		// resize : 용량 확보 이후 데이터 생성(초기화)
		{
			std:vector<int> V;
			V.reserve(10);		// capacity만 확보 size는 필요할때 마다 추가
			for (int i = 0; i < 10; i++)
			{
				V.push_back(i);
			}
			V.push_back(123);
			for (int i = 0; i < 100; i++)
			{
				V.push_back(i);
			}
		}
		{
			std::vector<int> V;
			V.resize(10);	// capacity와 size를 동시 확보
			for (int i = 0; i < 10; i++)
			{
				V[i] = i;
			}
			V.push_back(123);
		}

	}
#pragma endregion


}

