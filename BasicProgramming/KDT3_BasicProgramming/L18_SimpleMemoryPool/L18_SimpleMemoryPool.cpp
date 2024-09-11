// L18_SimpleMemoryPool.cpp : 간단한 메모리 풀
#include "Pool.h"


int main()
{
    // 일반적인 동적 할당
    {
        FClass* ClassInstance = new FClass;
        if (ClassInstance != nullptr)
        {
            ClassInstance->Print();
        }
        delete ClassInstance;
    }

    // malloc 메모리 공간만 할당(생성자와 소멸자가 호출이 안됨)
    {
        FClass* Memory = (FClass*)malloc(sizeof(FClass));
        // [중요] placement new : 이미 할당된 메모리 블록에 인스턴스를 만들어준다
        if (Memory != nullptr)
        {
            new(Memory)FClass();    // 생성자 호출
            Memory->Print();
        }
        Memory->~FClass();

        free(Memory);
    }


    // new, delete 성능 측정
    {
        int** Arr = new int* [MaxCount];

        // 시작 시간
        std::chrono::steady_clock::time_point Start{std::chrono::steady_clock::now()};
        
        
        {
            for (int i = 0; i < (int)MaxCount; i++)
            {
                int* Test = new int(i);
                Arr[i] = Test;
            }
            
            for (int i = 0; i < (int)MaxCount; i++)
            {
                delete Arr[i];
            }
        }

        // 종료 시간
        std::chrono::steady_clock::time_point End{std::chrono::steady_clock::now()};
        
        // 수행 시간 구하기
        auto Diff{ End - Start };

        delete[] Arr;

#if _DEBUG
        cout << format("Debug : ");

#else
        cout << format("Release : ");

#endif

        // 1sec == 1000ms , 1ms = 1000ns
        double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
        cout << format("[int] new , delete : {}ms\n", DiffCount);
    }


    // malloc, free 성능 측정
    {
        FClass** Arr = new FClass * [MaxCount];
        // 시작 시간
        std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };


        {
            for (int i = 0; i < (int)MaxCount; i++)
            {
                FClass* Test = (FClass*)malloc(sizeof(FClass));
                Arr[i] = Test;
            }

            for (int i = 0; i < (int)MaxCount; i++)
            {
                free(Arr[i]);
            }
        }

        // 종료 시간
        std::chrono::steady_clock::time_point End{ std::chrono::steady_clock::now() };

        // 수행 시간 구하기
        auto Diff{ End - Start };

        delete[] Arr;


#if _DEBUG
        cout << format("Debug : ");

#else
        cout << format("Release : ");

#endif

        // 1sec == 1000ms , 1ms = 1000ns
        double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
        cout << format("[int] malloc , free : {}ms\n", DiffCount);
    }
    
    // 직접구현한 고정사이즈 Memory Pool
    {
        int** Arr = new int* [MaxCount];
        FMemoryPool MemoryPool = FMemoryPool(sizeof(int), MaxCount);


        // 시작 시간
        std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };


        {
            for (int i = 0; i < (int)MaxCount; i++)
            {
                int* Test = (int*)MemoryPool.malloc();
                Arr[i] = Test;
            }

            for (int i = 0; i < (int)MaxCount; i++)
            {
                MemoryPool.free(Arr[i]);
            }
        }

        // 종료 시간
        std::chrono::steady_clock::time_point End{ std::chrono::steady_clock::now() };

        // 수행 시간 구하기
        auto Diff{ End - Start };

        delete[] Arr;

#if _DEBUG
        cout << format("Debug : ");

#else
        cout << format("Release : ");

#endif

        // 1sec == 1000ms , 1ms = 1000ns
        double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
        cout << format("[int] Custom MemoryPool malloc() , free() : {}ms\n", DiffCount);

    }


    // 직접구현한 고정사이즈 Memory Pool ( FClass )
    {
        FClass** Arr = new FClass * [MaxCount];
        FMemoryPool MemoryPool = FMemoryPool(sizeof(int), MaxCount);


        // 시작 시간
        std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };


        {
            for (int i = 0; i < (int)MaxCount; i++)
            {
                FClass* Test = (FClass*)MemoryPool.malloc();
                Arr[i] = Test;
            }

            for (int i = 0; i < (int)MaxCount; i++)
            {
                MemoryPool.free(Arr[i]);
            }
        }

        // 종료 시간
        std::chrono::steady_clock::time_point End{ std::chrono::steady_clock::now() };

        // 수행 시간 구하기
        auto Diff{ End - Start };

        delete[] Arr;

#if _DEBUG
        cout << format("Debug : ");

#else
        cout << format("Release : ");

#endif

        // 1sec == 1000ms , 1ms = 1000ns
        double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
        cout << format("[FClass] Custom MemoryPool  malloc() , free() : {}ms\n", DiffCount);

    }

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}
