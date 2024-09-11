// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		cout << "DLL이 외부 프로세스의 주소 공간에 최초로 매핑되었을때 이 DLL_PROCESS_ATTACH로 온다" << endl;
	}break;
	case DLL_THREAD_ATTACH:
	{
		cout << "외부 프로세스내 쓰레드가 생성될 때 매핑된 DLL을 검색 후 DLL_THREAD_ATTACH 호출" << endl;
	}break;
	case DLL_THREAD_DETACH:
	{
		cout << "외부 프로세스에서 ExitThread로 쓰레드를 종료할때 매핑된 DLL에 DLL_THREAD_DETACH 호출" << endl;
	}break;
	case DLL_PROCESS_DETACH:
	{
		cout << "DLL이 외부 프로세스의 주소 공간으로 부터 해제되었을 때 DLL_PROCESS_DETACH가 호출" << endl;
	}
	break;
	}
	return TRUE;
}

