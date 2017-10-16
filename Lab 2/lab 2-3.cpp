#include <iostream>  
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

	int max, min;
	max = mas[0];
	min = mas[0];

	for (i = 0; i < n; i++)
	{
		if (mas[i] < min)
			min = mas[i];
		if (mas[i] > max)
			max = mas[i];
	}

	int k;
	k = n;

	for (i = 0; i < n; i++)
	{
		if (mas[i] == max)
			k--;
	}

	int j = 0;

	int *mas1 = new int[k];
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (mas[i] != max)
				mas1[j] = mas[i];
			else
				mas1[j] = mas[i + 1];
		}
	}

	for (j = 0; j < k; j++)
	{
		cout << mas1[j] << " ";
	}

	system("pause");
	return 0;
}