#pragma once

#ifdef TEST_DLL
#define MYDLL_API __declspec(dllexport)		// DLL 외부 프로그램에 노출하겠다(즉, 이 DLL을 로딩한 프로그램이 접근하게 해줌)
#else
#define MYDLL_API __declspec(dllimport)		// DLL을 사용하는 외부 프로그램이 dllexport로 선언된 곳에 접근하겠다
#endif //  TEST_DLL

// extern "C" : C언어처럼 Name Mangling을 수행하지 않겠다. => Explicit Linking : 명시적 링킹
// Name Mangling : 컴파일러에 의해 이름이 변형되는 규칙 (calling convention에 영향을 받음)
// C++은 함수 오버로딩 지원 => 링커가 오버로딩된 함수들의 이름을 변경하여 구분 & 호출
// 그러나 보통 DLL에서는 복잡하니까 Explicit Linking(명시적 링킹)을 사용 
extern "C" MYDLL_API int Dll_Sum(int A, int B);