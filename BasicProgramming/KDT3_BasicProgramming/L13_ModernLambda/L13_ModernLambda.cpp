// L13_ModernLambda.cpp : 람다(Lambda)
#include <iostream>
#include <functional>
#include <format>

using namespace std;

int NormalAdd(int a, int b)
{
	return a + b;
}

//inline int InlineAdd(int a, int b)
//{
//	return a + b;
//}

__forceinline int InlineAdd(int a, int b)	// 인라인을 적용하는데 우선순위를 더 준다
{
	return a + b;
}


void NewFunction(std::function<void()> InFunction) 
{
	cout << "함수 이름 : " << __FUNCTION__ << endl;
	InFunction();
	cout << "함수 이름 : " << __FUNCTION__ << endl;
}

void Test()
{
	cout << "Test() 함수 콜" << endl;
}

int main()
{
#pragma region 인라인 함수
	{
		int A = 100, B = 50;
		int Ret = NormalAdd(A, B);

		cout << "NomalAdd : " << Ret << endl;
		cout << "NomalAdd의 Address: " << NormalAdd << endl;

		// 컴파일러가 함수를 복제해서 해당 코드위치에 넣어줌(보장 X) 
		// 컴파일러 본인 계산하에 인라인을 적용할지말지 결정함
		Ret = InlineAdd(A, B);	// 컴파일러가 Ret = A + B;로 바꿔서 인식
		cout << "InlineAdd : " << Ret << endl;
		cout << "InlineAdd의 Address: " << InlineAdd << endl;

		int p = 10;

	}
#pragma endregion

#pragma region 람다(Lambda) : 익명 함수
	cout << "람다(Lambda) Ex 1" << endl;
	{
		[]()
			{
				cout << "Lambda Function 호출불가 \n";
			};	// 마지막에 () 안넣으면 호출불기


		[]()
			{
				cout << "Lambda Function 호출 \n";
			}();

			std::function MyLambda = []()
				{
					static int s = 0;
					cout << format("MyLambda 호출 : {}\n", s++);
				};

			for (int i = 0; i < 2; i++)
			{
				MyLambda();
			}

			// 람다르 사용해서 파라미터 처리
			std::function MyLambda2 = [](const int inVal)
				{
					cout << format("MyLamda2 : {}", inVal);

				};

			for (int i = 0; i < 2; i++)
			{
				MyLambda2(10);
			}
	
	}
	{
		cout << "[람다(Lambda) EX 2]" << endl;
		{
			// 람다를 사용해서 외부 변수 캡쳐(기본적으로 읽기 전용)
			int a = 10, b = 20, c = 3000;

			// =를 사용하면 명시하지 않은 변수를 값으로 Capture 한다

			// &c는 외부 변수 수정 가능
			//  [a,b,&c](파라미터) -> 반환 자료형
			std::function MyLambda = [a, b, &c](const int inVal) -> int
			{
				c = 10;	// &가 붙어있으므로 외부 변수값을 수정 가능
				//a = 10; //컴파일 에러
				cout << std::format("외부 변수 캡쳐 [a:{}, b:{}, c:{}]\n", a, b, c);
				return inVal + 100;
			};
			int Value = MyLambda(100);

			cout << "람다 함수 리턴값 : " << Value << endl;
		}
		// 람다 주의사항
		{
			int a = 10, b = 20, c = 3000;

			// 명시적으로 a와 같이 캡처하는경울 값으로 Capture 함다(읽기 전용)
			std::function MyLambda = [&, a](const int inValue) ->int
				{
					//a = 20; // 컴파일 에러
					b = 30;
					c = 10;
					cout << std::format("외부 변수 캡처  [a:{}, b:{}, c:{}]\n", a, b, c);

					return inValue +100;
				};

			a = 999;	// 람다식으로 들어가면 10으로 이미 캡쳐 되었기에 람다함수 내에선 a 가10으로 작동한다
			int Value = MyLambda(100);
		}

		// 구조체 캡처
		{
			struct MyStruct
			{
				int value = 0;
				void setValue(int val) { value = val; }
			};

			MyStruct s;
			s.setValue(100);
			std::function MyLambda = [s]()
				{
					cout << "MyLambda 구조체캡쳐 : " << s.value << endl;
				};
			s.setValue(1313);	// 이미 위에서 캡쳐했기에 람다 값에 변화가 생기지 않음
			MyLambda();
			cout << s.value << endl;	// 이건 정상작동
		}

		//함수와 람다
		{
			NewFunction(Test);

			NewFunction([]()
				{
					for (int i = 0; i < 2; i++)
					{
						cout << std::format("람다식 : {}", i);
					}
					cout << endl;
				}
				
			);

			int Count = 5;
			NewFunction([Count]() {for (int i = 0; i < Count; i++) { cout << std::format("외부에서 Count 받은 람다 {}", i); }cout << endl; });
		}
	}
#pragma endregion


}

