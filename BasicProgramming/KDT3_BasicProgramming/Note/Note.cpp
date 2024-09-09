#include <iostream>



using namespace std;

int main()
{


	int n = 0;
	cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);
	int* b = (int*)malloc(sizeof(int) * n);

	int* sum = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n;i++)
	{
		cin >> a[i] >> b[i];
		sum[i] = a[i] + b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Case #"<< i+1<<": "<< a[i] << " + " << b[i] << " = " << sum[i] << "\n";
	}

	free(a);
	free(b);
	free(sum);
}