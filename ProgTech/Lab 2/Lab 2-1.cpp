#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	cout << "Введите число: ";
	int a;
	cin >> a;
	cout << a << " = ";
	int b = 2;
	 
	while (a > 1)
	{
		for (b = 2; b <= a; b++)
		{
			if (a%b == 0)
			{
				cout << b << " * ";				
				a = a / b;
				break;
			}
		}
	}

	cout << "\b\b" << " " << endl;
	system("pause");
	return 0;
}
