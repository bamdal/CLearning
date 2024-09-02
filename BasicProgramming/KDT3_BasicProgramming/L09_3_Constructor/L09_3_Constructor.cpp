#include <iostream>
using namespace std;
class CTranslation
{
public:
    double X, Y, Z=0;
    //CTranslation() {}     // default constructor(기본 생성자) -> 생성자 없이 초기화를 하면 기본생성자를 컴파일러가 만들어서 생성자를 만들지만
                            // 만약 초기화도 안하고 생성자도 없으면 컴파일러 최적화를 통해 생성자를 만들지 않는다
    CTranslation()  // 객체 생성시 호출되는 기본 생성자에서 맴버들을 초기화
    {
        X = 0;
        Y = 0;
        Z = 0;
    }

    // 생성자는 여러개를 가질 수 있다(맴버함수의 Overloading) => 특히 UE5 같은 거대 엔진은 이런 생성자들을 엄청 많이 제공한다.
    //CTranslation() : X(0), Y(0), Z(0) {} // 시그니처가 아니기 때문에 같은 생성자를 만들었다 판단함
    CTranslation(double inX, double inY, double inZ) : X(inX), Y(inY), Z(inZ)
    {
        
    }

    //CTranslation(double inX, double inY, double inZ = 100) : X(inX), Y(inY), Z(inZ)   // 디폴트인자를 사용한것도 같은 생성자로 판단
    //{
    //    
    //}
    CTranslation(double i, ...)
    {

    }

    // 복사 생성자 (call by reference)
    CTranslation(const CTranslation& obj)
    {
        X = obj.X;
        Y = obj.Y;
        Z = obj.Z;
        // 이렇게 참조자로 받으면 원본값을 변경할 수 있음 그래서 const를 붙여준다(관례)
        //obj.X = 8888;   // const 키워드 쓰면 컴파일 에러
 
    }
};

class CRotation
{
public:
    double X, Y, Z;

    CRotation() // 객체 생성시 호출되는 기본 생성자에서 맴버를 초기화
    {
        X = 0;
        Y = 0;
        Z = 0;
    }

    // 복사 생성자 만들어 보자
    CRotation(const CRotation& obj)
    {
        X = obj.X;
        Y = obj.Y;
        Z = obj.Z;
    }
};

class CScale
{
public:
    double* _scale;

    CScale()
    {
        _scale = new double[3];
        for (int i = 0; i < 3; i++)
        {
            _scale[i] = 100 + i;
        }
    }
    ~CScale()
    {
        delete[] (_scale);
    }

    explicit CScale(const CScale& obj)
    {
        _scale = new double[3];
        for (int i = 0; i < 3; i++)
        {
            _scale[i] = obj._scale[i];  // 깊은 복사
        }
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            if (_scale != nullptr)
            {
                cout << _scale[i] << " ";
            }
        }
        cout << endl;


    }
};
int main()
{
#pragma region
    {
        CTranslation T1;
     
        CTranslation(10, 10);

        CTranslation T2(10, 10,10);    // 오버로딩된 생성자 호출

        CTranslation T3 = T2;   // 객체의 복사 => 모든 메모리가 복제하는 방식(맴버가 수백수천개면 비효율적이다)

        CTranslation T4(T2);    // 이렇게 자주 쓴다    같은 주소를 쓰기에 값이 하나 변경되면 같이 변경됨
        T4.X = 8888;


        // 복사 생성자 사용시 주의점 1
        CRotation R1;   // 컴파일 에러(디폴트 생성자를 호출해야 하는데, 위에서 복사생성자를 만들었기 때문에 컴파일러가 디폴트생성자를 만들어 주지 않는다.)
        R1.X = 100;
        R1.Y = 100;
        R1.Z = 100;

        CRotation R2(R1);

        // 복사 생성자 사용시 주의점 2

        CScale S1;
        S1.print();

        //CScale S2 = S1;   // 복사 생성자를 컴파일러가 자동 생성하면 얕은 복사가 일어나 주소만 넘어가 S2의 값 변경시 S1도 연달아 교체된다.
                            // explicit 사용해 얕은 복사가 일어나는걸 막을수 있음 
        CScale S2(S1);
        S2.print();

        S2._scale[0] = 123, S2._scale[1] = 456, S2._scale[2] = 789;
        S2.print();

        S1.print(); // 얕은 복사는 S1값도 바뀐다

        int ll = 0;
    }

#pragma endregion

}
