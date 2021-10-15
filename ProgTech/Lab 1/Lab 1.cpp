#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int sum = 0;
	while (true)
	{
		cout << "Введите сумму в копейках: " << endl;
		cin >> sum;
		cout << "Итого: ";
		if (sum == 0)
			cout << "Ничего не куплено!" << endl;
		else
		{
			int kop = 0;
			int rub = 0;
			rub = sum / 100;
			kop = sum % 100;
			if (rub != 0)
			{
				if ((rub > 4) && (rub < 20) || (rub % 10 == 0) || (rub % 10 > 4) && (rub % 10 < 10))
					cout << rub << " рублей ";
				else if ((rub == 1) || (rub % 10 == 1))
					cout << rub << " рубль ";
				else if ((rub <= 4) || (rub % 10 == 2) || (rub % 10 == 3) || (rub % 10 == 4))
					cout << rub << " рубля ";
			}
			if (kop != 0)
			{
				if ((kop > 4) && (kop < 20) || (kop % 10 == 0) || (kop % 10 > 4) && (kop % 10 < 10))
					cout << kop << " копеек ";
				else if ((kop == 1) || (kop % 10 == 1))
					cout << kop << " копейка ";
				else if ((kop <= 4) || (kop % 10 == 2) || (kop % 10 == 3) || (kop % 10 == 4))
					cout << kop << " копейки ";
			}

		}
		cout << endl;
	}
	system("pause");
	return 0;
}
