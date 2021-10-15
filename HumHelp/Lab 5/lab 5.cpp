#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int *mas = new int;
	cout << "Введите размерность массива: ";
	int n = 0;
	cin >> n;
	cout << "Введите массив: ";
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] < mas[i + 1]) count++;
		else
		{
			count = 0; 
			break;
		}
	}
	if (count == 0) cout << "Последовательность не является возрастающей!" << endl;
	else cout << "Последовательность является возрастающей!" << endl;
	system("pause");
	return 0;
}
