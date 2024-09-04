#pragma once
#include <iostream>
using namespace std;



template<class T, size_t WIDTH = 640,size_t HEIGHT = 480>
class TClass
{
private:
	T Value{};
	size_t Width = WIDTH;
	size_t Height = HEIGHT;
public:
	size_t GetWidth() const { return Width; }
	size_t GetHeight() const { return Height; }
	size_t GetDefaultWidth() const { return WIDTH; }
	size_t GetDefaultHeight() const { return HEIGHT; }

	void SetWidth(const size_t InWidth) { Width = InWidth; };
	void SetHeight(const size_t InHeight) { Height = InHeight; };

	void Function(const T& InValue)
	{
		Value = InValue;
	}

	template<typename T2>
	T2 Function2()
	{
		T2 Var = 10;
		return Var + Width;
	}

};

template<typename T,size_t WIDTH,size_t HEIGHT>
class TClass2 : public TClass<T, WIDTH, HEIGHT>
{

};

template<typename T>
class TClass3 : public TClass<T, 640, 240>
{

};
