// L14_Contanier.cpp : STL 컨테이너

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
#include <format>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

bool ReturnTrue()
{
	return true;
}

int main()
{
#pragma region auto : 타입 추론 (type deduction) / decitype : 타입 추론
	{
		// 타입 추론 : 컴파일러가 타입을 추론해주는 기능 -> 변수 선언, 초기화 시 
		// 타입 추출 : 함수의 반환값 레퍼런스(&), 상수(const)도 정확하게 추론
		// 무분별하게 사용시 컴파일 시간이 살짝 늘어나긴 한다 => 고민할 수준은 아님Ⅰ
		int a = 10;
		auto aa = 10;			// 정수형 리터럴은 기본적으로 int로 추론
		auto Double = 3.0;		// 실수 리터럴은 double
		auto Float = 3.5f;		// 명시적으로 f를 쓰면 flaot로 추론


		auto var1{ 10 };
		auto var2 = 10;

		bool bRet = ReturnTrue();
		auto bRet2 = ReturnTrue();

		int i = 100;
		int* intPtr = &i;
		auto autoPtr = &i;
		auto* atPtr = &i;
		auto intAuto = i;
		auto& refIntAuto = i;
	}
#pragma endregion

#pragma region Vector(벡터 : 동적 배열)

	// [vector] (TArray : Unreal vector)
	// 원소를 저장하고 각 원소에 임의 접근(random access)이 가능
	// 배열이니까 원소를 메모리 공간에 연속적으로 저장
	// 동적 배열이기에 저장된 원소 수에 따라 크기가 자동으로 증감한다.
	// 마지막(끝)에 원소를 추가하거나 삭제하는 연산을 매우 빠르게 처리(시간복잡도 O(1))
	// 원소가 추가될 때 컨테이너가 부족한 경우 메모리를 늘려야 하기 때문에 (공간복잡도 O(N))
	// (주의!!) 끝이 아닌 공간에 원소를 추가/삭제시 느릴 수 밖에 없다. >> 관련 원소들을 한칸씩 이동시켜야 하니까(O(N))
	// 모든 원소를 조회(random access)하는 경우 걸리는 시간은 배열처럼 상수 시간 소비 -> 아주 빠르다
	// 일반적으로 원소의 개수가 적은 경우 다른 컨테이터보다 vector가 더 빠르다
	{
		cout << "[STL Vector : 동적배열]" << endl;

		std::vector<int> V1{ 5,3,4 };
		std::vector V2{ 5,3,4 };
		std::vector V{ 1.5,3.5,4.4 };

		std::vector<int> V3;	// 타입 추론은 해놔야 선언만 하고 끝낼수 있음

		V3.push_back(11);
		V3.push_back(22);
		V3.push_back(33);

		int i = 0;

	}
	{
		// 콘텐츠 개발시 대략적으로(또는 명확하게)size를 예상할 수 잇는 경우 반드시
		// reserve: capacity(용량)는 *1.5배씩 사이즈가 계속 늘어난다
		// resize : 용량 확보 이후 데이터 생성(초기화)
		{
			std:vector<int> V;
			V.reserve(10);		// capacity만 확보 size는 필요할때 마다 추가
			for (int i = 0; i < 10; i++)
			{
				V.push_back(i);
			}
			V.push_back(123);
			for (int i = 0; i < 100; i++)
			{
				V.push_back(i);
			}
		}
		{
			std::vector<int> V;
			V.resize(10);	// capacity와 size를 동시 확보
			for (int i = 0; i < 10; i++)
			{
				V[i] = i;
			}
			V.push_back(123);
		}

	}
	// iterator / erase, insert
	{
		vector<int> v;
		v.reserve(10);
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		// iterator : 컨테이너내를 순회한다 v.begin()은 인덱스0번, v.end()는 인덱스n+1번
		vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
		if (it != v.end())	// 못찾으면 end()가 들어간다
		{
			cout << v[4] << endl;

			v.erase(it);	// 찾은 값을 지운다
			cout << v[4] << endl;
		}
		v.erase(v.begin() + 1);	// 인덱스 1번값삭제	뒤에 값들이 앞으로 당겨온다
		v.erase(v.end() - 1);	// 맨 마지막 값 삭제

		v.insert(v.begin() + 4, 1000);	// 뒤에 값들이 밀리게 된다

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}

		// modern C++ 기능 (범위 기반 for)
		for (int Value : v)	// 벡터 끝까지 간다
		{
			cout << Value << endl;
		}

		int iSize = (int)v.size();	
		for (int i = 0; i < iSize; i++)
		{

		}
	}
#pragma endregion

#pragma region list (doubly linked list : 이중 연결 리스트)
	{
		cout << "[STL List : 이중 연결 리스트]" << endl;
		std::list<int> List;

		for (int i = 0; i < 10; i++)
		{
			List.push_back(i);
		}

		std::list<int>::iterator it = List.begin();

		int a = *it;
		int b = *(++it);
		int c = *(--it);
		int d = *(it++);
		int e = *(it--);


		list<int>::iterator it2 = List.insert(it, 1000);	 // 삽입후 해당 위치의 이터레이터를 반환 기존값은 뒤로 밀림
		List.erase(it2);	// 이터레이터가 가리키는 노드를 삭제하지만 벡터처럼 뒤에 값들을 당겨오지 않는다
		// it2는 Dangling Pointer(가르키는 포인터가 이미 해제되어있다)


		cout << a << " " << b << " " << c << " " << d << " " << e << endl;

		list<int>::iterator it3 = List.begin();

		for (; it3 != List.end(); it3++)
		{
			cout << *it3 << endl;
		}

		auto it4 = List.begin();	// 타입 추론
		for (; it4 != List.end(); it4++)
		{
			cout << *it4 << endl;
		}



	}
#pragma endregion

#pragma region queue(FIFO) / UE TQueue
	{
		// 컨테이너 한쪽 끝에서만 원소를 추가하고, 다른 쪽 끝에서는 꺼내기만 한다.
		cout << "[STL Queue : 큐]" << endl;

		std::queue<int> Queue;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				Queue.push(i);

			}
			else
			{
				Queue.emplace(i);	// 클래스 객체일 경우 좀 더 빠르다

			}
		}

		// push : 생성된 객체 or 객체를 생성한 뒤 복사하여 넘겨줌(move) [생성자] => [복사생성자] / 즉 ,임시객체가 만들어져서 추가 메모리를 쓴다.
		// emplace : 객체 생성에 필요한 (가변)인자를 forward로 넘겨줌 / 생성자를 다이렉트로 호출 

		//int num = Queue[0];	// 컴파일 에러(Random access 불가능) iterator못씀
		
		int num = Queue.front(); // 첫번째 원소 값 반환
		

		size_t Size = Queue.size();

		cout << "Queue의 남은 인자 개수 : " << Size << endl;

		// 큐의 pop 명령
		cout << "Queue의 pop 처리" << endl;
		while (!Queue.empty())
		{
			int value = Queue.front();
			cout << value << endl;
			Queue.pop();
		}

		Size = Queue.size();

		cout << "Queue의 남은 인자 개수 : " << Size << endl;
		
		
		cout << "[STL Priority Queue : 우선순위 큐]" << endl;


		// 내림차순 정렬
		std::priority_queue<int, std::vector<int>, std::less<int>> PQ;
		PQ.push(50);
		PQ.push(30);
		PQ.push(70);
		PQ.push(680);
		PQ.push(25);
		PQ.push(250);
		PQ.push(25);


		cout << "priorty_queue의 오름차순 pop 처리\n";
		while (!PQ.empty())
		{
			cout << PQ.top() << endl;
			PQ.pop();
		}


		// 오름차순 정렬
		std::priority_queue<int, std::vector<int>, std::greater<int>> PQ2;
		PQ2.push(50);
		PQ2.push(30);
		PQ2.push(70);
		PQ2.push(680);
		PQ2.push(25);
		PQ2.push(250);
		PQ2.push(25);


		cout << "priorty_queue의 내림차순 pop 처리\n";
		while (!PQ2.empty())
		{
			cout << PQ2.top() << endl;
			PQ2.pop();
		}
		int ii = 0;


	}
	// 람다를 사용한 여러 큐를 사용해서 우선순위로 분리
	{
		std::queue<std::string> Channel1;
		std::queue<std::string> Channel2;
		std::queue<std::string> Channel3;

		enum class EPriority	// 채팅창 탭
		{
			Channel1,	// 귓속말
			Channel2,	// 인게임 메시지
			Channel3,	// 시스템 공지
		};

		
		std::function MyLambda = [&](const EPriority InPriority, std::string str)
			{
				switch (InPriority)
				{
				case EPriority::Channel1:
					Channel1.push(str);
					break;
				case EPriority::Channel2:
					Channel2.push(str);
					break;
				case EPriority::Channel3:
					Channel3.push(str);
					break;
				default:
					_ASSERT(false);	// 예외처리
					break;
				}
			};

		MyLambda(EPriority::Channel2, "게임 채팅 2_1번");
		MyLambda(EPriority::Channel1, "게임 채팅 1_1번");
		MyLambda(EPriority::Channel1, "게임 채팅 1_2번");
		MyLambda(EPriority::Channel3, "게임 채팅 3_1번");
		MyLambda(EPriority::Channel2, "게임 채팅 2_2번");
		MyLambda(EPriority::Channel2, "게임 채팅 2_3번");
		MyLambda(EPriority::Channel3, "게임 채팅 3_2번");

		std::cout << "[Channel1 ]\n";
		while (!Channel1.empty())
		{
			cout << Channel1.front() << endl;
			Channel1.pop();
		}
		std::cout << "[Channel2 ]\n";
		while (!Channel2.empty())
		{
			cout << Channel2.front() << endl;
			Channel2.pop();
		}
		std::cout << "[Channel3 ]\n";
		while (!Channel3.empty())
		{
			cout << Channel3.front() << endl;
			Channel3.pop();
		}
	}
#pragma endregion

#pragma region stack (LIFO)
	{
		cout << "[STL Stack : 스택]" << endl;

		std::stack<int> Stack;
		for (int i = 0; i < 10; i++)
		{
			cout << i << endl;
			Stack.push(i);
		}

		cout << "stack pop" << endl;

		while (!Stack.empty())
		{
			int value = Stack.top();
			cout << value << endl;
			Stack.pop();
		}
	}
#pragma endregion

#pragma region map
	{
		// pair : 두 데이터를 들고 있는 컨테이너
		{
			std::pair<std::string, std::string> Pair{"Hello(key)","World(value)"};
			cout << std::format("Key : {}, Value : {}\n", Pair.first, Pair.second);

			std::pair<int, std::string>Pair2{ 1004,"Player" };
			cout << std::format("Key : {}, Value : {}\n", Pair2.first, Pair2.second);

			std::pair<std::string, double>Pair3{ "Player",3.141592 };
			cout << std::format("Key : {}, Value : {}\n", Pair3.first, Pair3.second);
		}

		// map : pair의 컨테이너 (UE TMap)
		// Red-Black Tree로 구현 => 자가 균형 이진 탐색 트리
		// 원소의 키를 기준으로 정렬되어 데이터를 관리
		// Key-Value를 쌍으로 저장해 빠르게 검색할 때 map을 사용
		// [추가/삭제 연산 속도] list / map / vector 순서로 빠름
		// [데이터 조회 속도] vector(O(1)) / map / list(O(n)) 순으로 빠름 vector는 random access가능
		// 원소의 순서 유지가 주 목적이고 [추가/삭제/조회] 연산을 골고루 사용해야 하는 컨테이너 필요시 map이 무난
		// map은 동일 키에 대해 하나의 값만 보관(중복키 허용X)
		// 동일키에 대해 여러값을 보관하려면 multimap을 사용
		{
			std::map<int, std::string/*, std::greater<int>*/> Map;
			Map.insert(std::make_pair(999, "NickName"));
			Map.insert(std::make_pair(999, "Ignore"));	// insert시 이미 중복된 키값이 있으면 무시한다
			Map[999] = "ChangeValue";					// 배열 인덱스처럼 Key값을 찾아 값을 수정(벡터처럼 인덱스로 접근하는건 아님)
			Map[0] = "Hello";							// 0번 키값이 비어있으면 insert인것 처럼 수행한다.
			// *배열처럼 수행될뿐 배열과는 다르다*
			Map[123] = Map[0];
			
			std::map<int, std::string>::iterator it = Map.find(999);
			auto it2 = Map.find(7);	// 형식 추론

			if (it2 == Map.end())
			{
				cout << "해당키를 못찾음" << endl;
			}

			if (it != Map.end())
			{
				cout << format("key : {}, value : {}\n", it->first, it->second);
			}


			for (int i = 0; i < 20; i++)
			{
				Map[i] = "Hello" + std::to_string(i + 65);	// 해당 키값이 있으면 수정 없으면 생성
			}
			

			cout << "map 전체 출력" << endl;
			// map 전체 출력
			for (auto& Pair : Map)
			{
				cout << format("key : {}, value : {}\n", Pair.first, Pair.second);
			}

			cout << endl << "map의 value 수정후 출력\n";
			int i = 0;
			for (auto it = Map.begin(); it != Map.end(); it++, i++)	// 증감 2개 가능
			{
				if (i % 2 == 0)
				{
					it->second = "!CAT!";
				}
				else
				{
					it->second = "!DOG!";
				}
				cout << format("key : {}, value : {}\n", it->first, it->second);
			}

			
			int ii = 0;


		}
	}
#pragma endregion


}

