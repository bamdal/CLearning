#pragma once

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

const size_t MaxCount = (4096 * 1000);	// 4 mbyte

class FClass
{
public:
	FClass();
	virtual ~FClass();
	void Print();


private:
	char Data[1024] = {};

};

FClass::FClass()
{
	cout << __FUNCTION__ << endl;
}

FClass::~FClass()
{
	cout << __FUNCTION__ << endl;
}

inline void FClass::Print()
{
	cout << "FClass Print() 호출" << endl;
}

// 고정 사이즈 Memory pool
class FMemoryPool
{
public:
	FMemoryPool(const size_t InChunkSize, const size_t InChunkcount) noexcept;
	virtual ~FMemoryPool();
	FMemoryPool(const FMemoryPool&) = delete;
	FMemoryPool& operator=(const FMemoryPool&) = delete;

	void* malloc();
	void free(void* InMemory);
private:
	const size_t ChunkSize;
	const size_t ChunkCount;
	void* StartAddress = nullptr;
	std::vector<void*> ActiveMemoryBlock;

};


FMemoryPool::FMemoryPool(const size_t InChunkSize, const size_t InChunkcount) noexcept
	:ChunkSize(InChunkSize), ChunkCount(InChunkcount)
{
	const size_t Align = 8;
	// InChunkSize : 4
	// Align : 8
	// 4 + (8 - 1) == 11;
	// 11 == 1011(2진수)
	// ~(8 - 1) -> ~(0111) -> (1000)
	// (1011) & (1000) == (1000)
	const size_t AlignedChunkSize = ((InChunkSize + (Align - 1)) & ~(Align - 1));
	const size_t TotalMemorySize = AlignedChunkSize * ChunkCount;
	StartAddress = _aligned_malloc(TotalMemorySize, Align);

	ActiveMemoryBlock.reserve(InChunkSize);
	for (size_t i = 0; i < ChunkCount; i++)
	{
		uint8_t* Memory = (uint8_t*)StartAddress + i*InChunkSize;
		ActiveMemoryBlock.emplace_back(Memory);
	}
}

FMemoryPool::~FMemoryPool()
{
	_ASSERT(StartAddress);
	::_aligned_free(StartAddress);
}

inline void* FMemoryPool::malloc()
{
	if (ActiveMemoryBlock.empty())
	{
		// 남은 Memory가 pool에 없다
		_ASSERT(false);
		return nullptr;

	}

	void* Memory = ActiveMemoryBlock.back();
	ActiveMemoryBlock.pop_back();
	return Memory;

}

inline void FMemoryPool::free(void* InMemory)
{
	ActiveMemoryBlock.emplace_back(InMemory);

}
