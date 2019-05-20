#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int n=0;
	cout << "Введите размерность массива: ";
	cin >> n;
	int *Z = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> Z[i];
	}

	int max = Z[0];
	int min = Z[0];
	int k = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		if (Z[i] > max)
		{
			max = Z[i];
			k = i;
		}
		if (Z[i] < min)
		{
			min = Z[i];
			m = i;
		}
	}

	for (int i = k; i < n-1; i++)
	{
			Z[i] = Z[i + 1]; 
			n--;
	}

	for (int i = m; i < n-1; i++)
	{
		Z[i] = Z[i + 1];
		n--;
	}

	cout << "Полученный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << Z[i] << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}
