#include <iostream>
using namespace std;

int main()
{
	
	int n = 0;

	cin >> n;

	int* num = (int*)malloc(sizeof(int)*n);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		a = 0, b = 0;
		cin >> a >> b;
		num[i] = a + b;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << endl;
	}

	free(num);

}