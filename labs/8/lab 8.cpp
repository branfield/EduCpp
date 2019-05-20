#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите размерность массива A: ";
	cin >> n;
	int *A = new int[n];
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i] % 2 == 0) k++;
	}

	int *B = new int[k];
	int sum = 0;

	for (int i = 0, j = 0; i < n; i++)
	{
		if (A[i] % 2 == 0)
		{
			B[j] = A[i];
			j++;
		}
		else sum += A[i];
	}

	cout << "Массив B: "; 

	for (int i = 0; i < k; i++)
	{
		cout << B[i] << " ";
	}

	cout << endl << "Сумма нечетных элементов массива A: " << sum << endl;

	system("pause");
	return 0;
}
