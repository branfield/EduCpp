#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int Z[100];
	int n = 0;
	int max = 0;
	int n_max = 0;
	int min = 0;
	int n_min = 0;

	cout << "Введите размерность массива: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Z[i];
	max = Z[0];
	min = Z[0];
	for (int i = 0; i < n; i++)
	{
		if (Z[i] > max) { max = Z[i]; n_max = i; }
		if (Z[i] < min) { min = Z[i]; n_min = i; }
	}

	for (int i = n_max; i < n - 1; i++)
		Z[i] = Z[i + 1];
	n--;
	for (int i = n_min; i < n - 1; i++)
		Z[i] = Z[i + 1];
	n--;
	cout << "Полученный массив: ";
	for (int i = 0; i < n; i++) cout << Z[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
