// L11_Template.cpp : 템플릿 함수 / 템플릿 클래스
#include"TClass.h"
#include <iostream>

using namespace std;

int Sum(const int a, const int b)
{
	return a + b;
}

double Sum(const double a, const double b)
{
	return a + b;
}

template<typename T>
T TemplateSum(const T& a, const T& b)
{
	return a + b;
}

int Sum2(const int a, const int b = 20)
{
	return a + b;
}

template<class T1, typename T2, typename T3 = double>	// T3를 double형으로 (매개변수 타입도 매개변수화)
T3 TempleteSum2(const T1& a, const T2& b)
{
	return (T3)a + b;
}

int main()
{
#pragma region 템플릿 함수
	{
		// 일반 함수
		{
			double A = 20, B = 100;

			int i = Sum(10, 10);
			double d = Sum(A, B);

			int ii = 0;
		}
		// 템플릿 함수
		{
			short s = TemplateSum<short>(1, 2);
			int i = TemplateSum<int>(123, 532);
			double d = TemplateSum<double>(123.24, 213.54);
			float f = TemplateSum<float>(13.41, 12.3);

			int ii = 0;

		}
		// 일반함수(디폴트 인자 O)
		{
			int i = Sum2(10);	// 디폴트 인자 때문에 뒤에 파라메터 생략

			double d = TempleteSum2<float, double>(TemplateSum<float>(10.5, 50.5), 45.5);

			d = TempleteSum2<int, int>(TemplateSum<int>(15.1, 10), 5.5);
			int ii = 0;
		}
	}
#pragma endregion

#pragma region 템플릿 클래스
	{
		TClass<int, 1920, 1080> instance;
		size_t Width = instance.GetDefaultWidth();
		size_t Height = instance.GetDefaultHeight();

		TClass<int, 1234, 10> instance2;
		size_t Width2 = instance2.GetDefaultWidth();
		size_t Height2 = instance2.GetDefaultHeight();

		instance.Function(10);

		double ResultWidth = instance.Function2<double>();

		int ii = 0;
	}

#pragma endregion

}

