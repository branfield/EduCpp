#include <iostream> 
#include <cmath> 
using namespace std;
int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	int *mas = new int[n];
	int i = 0;

	for (i = 0; i < n; i++)
	{
		cin >> mas[i];
	}

	int k = 0, l = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
			k++;
	}

	for (i = 0; i < n; i++)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] == a[i + 1])
				k++;
		}
		if (k > l)
			l = k;
	}

	cout << l;
	system("pause");
	return 0;
}