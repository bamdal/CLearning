#include <iostream>
using namespace std;

bool TestFunc(int Num, int N)
{
    bool result = false;
    if (N !=0 && Num % N == 0)
    {
        result = true;
    }

    return result;
}

int main()
{
    int Num =0, N=0;
    cout << "정수 Num 입력 : ";
    cin >> Num;
    cout << "\n정수 N 입력 : ";
    cin >> N;

    if (TestFunc(Num, N))
    {
        cout << Num << "은 " << N << "의 배수입니다";
    }
    else
    {
        cout << Num << "은 " << N << "의 배수가 아닙니다";
    }



}
