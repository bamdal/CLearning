// L19_Engine.cpp : 엔진 (UE 방식)
#include <string>
#include <Windows.h>
#include <iostream>
#include "framework.h"
using namespace std;

typedef int (*DLL_SUM)(int a, int b);

int main()
{
#pragma region DLL 함수 사용1
    {
        // 옛날 방식
        bool go = true;
        if (!go)
        {
#ifdef _DEBUG
            string path = "..\\DLL\\L20_DLL_d.dll";
#elif NDEBUG
            string path = "..\\DLL\\L20_DLL_r.dll";
#endif // _DEBUG

            HMODULE hDll = ::LoadLibraryA(path.c_str());    // DLL_PROCESS_ATTACH
            if (hDll != NULL)
            {
                DLL_SUM pFunc = (DLL_SUM)::GetProcAddress(hDll, "Dll_Sum");
                int Ret = pFunc(40, 60);
                cout << "Ret : " << Ret << endl;
                ::FreeLibrary(hDll);    // DLL_PROCESS_DETACH
                cout << "adsf" << endl;
            }
        }

    }
#pragma endregion

#pragma region DLL 함수 사용 2
    {
        bool go = true;
        if (go)
        {
            // 프로젝트 속성->링커->입력에 걸어놨기에 사용가능
            int Ret = Dll_Sum(40, 60);
            cout << "Ret : " << Ret << endl;
        }

    }
#pragma endregion


    
}

