#pragma once
#include <iostream>
#include <format>

using namespace std;

class CTranslation
{
public:
	CTranslation(double _x, double _y, double _z);
	~CTranslation();

	// 연산자 (+) 오버로딩
	CTranslation operator + (const CTranslation& Obj);
	CTranslation operator - (const CTranslation& Obj);
	CTranslation operator / (const CTranslation& Obj);

	// 데이터 타입 변환에 대한 연산자 오버로딩
	operator double() const;

	// 프랜드 함수로 << 오버로딩
	friend ostream& operator << (ostream&, const CTranslation&);
	
	void SetN1(int n1);
	void SetN2(int n2);

	void Print()
	{
		cout << format("[X : {}, Y : {}, Z : {}]", X, Y, Z) << endl;
	}
private:
	double X, Y, Z;
	int N1, N2;
	
};

CTranslation::CTranslation(double _x, double _y, double _z) : X(_x), Y(_y), Z(_z)
{
	N1 = N2 = 0;
}

CTranslation::~CTranslation()
{
}

inline CTranslation CTranslation::operator+(const CTranslation& Obj)
{
	int x = X + Obj.X;
	int y = Y + Obj.Y;
	int z = Z + Obj.Z;

	return CTranslation(x,y,z);
}

inline CTranslation CTranslation::operator-(const CTranslation& Obj)
{
	int x = X - Obj.X;
	int y = Y - Obj.Y;
	int z = Z - Obj.Z;

	return CTranslation(x, y, z);
}

inline CTranslation CTranslation::operator/(const CTranslation& Obj)
{
	double x = 0;
	double y = 0;
	double z = 0;
	
	if (Obj.X * Obj.Y * Obj.Z != 0)
	{
		x = (double)X / Obj.X;
		y = (double)Y / Obj.Y;
		z = (double)Z / Obj.Z;
	}

	
	return CTranslation(x,y,z);
}

/// <summary>
/// double 타입 변환 연산자 오버로딩
/// CTranslation클래스에서 double 형으로 뭘 달라하면 뭘 줄지 미리 설정
/// </summary>
inline CTranslation::operator double() const
{
	if (N2 != 0)
	{
		return double(N1) / N2;

	}
	else
	{
		cout << "0나누기 불가";
		return 0;
	}
}

inline void CTranslation::SetN1(int n1)
{
	N1 = n1;
}

inline void CTranslation::SetN2(int n2)
{
	N2 = n2;
}

ostream& operator<<(ostream&, const CTranslation& T)
{
	return cout << format("[X : {}, Y : {}, Z : {}]\n", T.X, T.Y, T.Z);
}



