#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(0));
	int mas[9][9];
	int n = 9;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = rand() % 70 - 35;
		}
	}

	cout << "ИСХОДНЫЙ МАССИВ: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << "  ";
		}
		cout << endl;
	}

	for (int i = 0, j = n - 1; i < n; i++, j--)
	{
		int sum = 0;
		for (int k = i, l = j; (k >= 0) && (l >= 0); k--, l--)
		{
			sum += mas[k][l];
		}
		mas[i][j] = sum;
	}

	cout << endl << endl <<  "ПОЛУЧЕННЫЙ МАССИВ: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j]>9)
				cout << mas[i][j] << " ";
			else
				cout << mas[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
