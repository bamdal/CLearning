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
    CTranslation(CTranslation& obj)
    {
        X = obj.X;
        Y = obj.Y;
        Z = obj.Z;
        // 이렇게 참조자로 받으면 원본값을 변경할 수 있음 그래서 const를 붙여준다(관례)
        obj.X = 8888;   // const 키워드 쓰면 컴파일 에러
 
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
        int ll = 0;
    }

#pragma endregion

}
