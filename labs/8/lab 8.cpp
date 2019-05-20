#include<iostream>
using namespace std;

int *repet(int *mas, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i] == mas[j]) k++;
		}
		if (k > 2)
		{
			for (int j = 0; j < n; j++)
			{
				mas[i] = mas[i + 1];
				i++;
			}
			n--;
		}
	}
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "¬ведите размерность массива: ";
	cin >> n;
	int *mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}

	system("pause");
	return 0;
}