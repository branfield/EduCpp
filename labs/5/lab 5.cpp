#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите размерность массива: ";
	cin >> n;
	int *mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}

	int max = mas[0];
	int min = mas[0];

	for (int i = 0; i < n; i++)
	{
		if (mas[i] > max) max = mas[i];
		if (mas[i] < min) min = mas[i];
	}

	cout << "Полученный массив: ";
	for (int i = 0; i < n; i++)
	{
		if (mas[i] == max || mas[i] == min) continue;
		else  cout << mas[i] << " "; 
	}
	system ("pause");
	return 0;
}