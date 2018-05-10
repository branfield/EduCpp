#include <iostream>
#include <windows.h>
using namespace std;

class Rect
{

	int x1, y1, x2, y2;

public:

	Rect(int abs1, int ord1, int abs2, int ord2)
	{
		this->x1 = abs1;
		this->y1 = ord1;
		this->x2 = abs2;
		this->y2 = ord2;
	}

	void size(int input, int multiplier)
	{
	
	}

	void move(int s1, int s2)
	{

	}

	void connection()
	{
		int x3 = x1;
		int y3 = y1;
		int x4 = x2;
		int y4 = y2;
		cout << "Действие требует дополнительного ввода значений" << endl;
		constructor();
	}

	void leastUnion()
	{

	}

	~Rect()
	{
	}
};


int FoolProtection(char* buff = new char)
{
	bool flag = true;
	while (true)
	{
		bool normal = true;
		for (int i = 0; i < strlen(buff); i++)
		{
			if (buff[i] < '0' || buff[i] > '9')
			{
				normal = false;
				break;
			}
		}

		if (!normal)
		{
			cout << "������ �����. ������� �����. " << endl;
			break;
		}
		else
		{
			return atoi(buff);
			return 0;
			flag = false;
			break;
		}
	}
} 

int main()
{
	setlocale(0, "");
	char* x1 = new char;
	char* y1 = new char;
	char* x2 = new char;
	char* y2 = new char;
	int a = 0;
	bool condition = false;
	while (!condition)
	{
		cout << "������� ���������� ��������������" << endl << "���������� ������� �����: " << endl;
		while (1)
		{
			cout << "x = ";
			cin >> x1;
			FoolProtection(x1);
			if (!FoolProtection)
				break;
		}
		while (a != 1)
		{
			cout << "y = ";
			cin >> y1;
			FoolProtection(x1);
		}
		FoolProtection(y1);
		cout << endl << "���������� ������ �����: " << endl << "x = ";
		cin >> x2;
		FoolProtection(x2);
		cout << "y = ";
		cin >> y2;
		FoolProtection(y2);
		int height = 0, widht = 0;
		height = y1 - y2;
		widht = x2 - x1;
		if ((height <= 0) || (widht <= 0)) cout << "������������ ��������. ��������� ����." << endl;
		else condition = true;
	}

	//Rect program(x1, y1, x2, y2);

	bool flag = false;
	while (!flag)
	{
		cout << endl << endl << "�������� ������ ��������: " << endl;
		cout << "(1) � ����������� ������ �� ���������" << endl;
		cout << "(2) � ��������� ������� ������" << endl;
		cout << "(3) � ���������� ����������� ��������������, ����������� ��� �������� ��������������" << endl;
		cout << "(4) � ���������� ����������� ��������������, ����������� ������������ ���� �������� ��������������" << endl;
		cout << "(5) � �����" << endl;

		int e=0, s1=0, s2=0;
		cout << endl;
		cin >> e;

		/*switch (e)
		{
		case 1:
			cout << "�������� ������ �������� ��� �����������" << endl;
			cout << "(1) � ���������" << endl << "(2) � ���������" << endl << "(3) � ����� � ����" << endl;
			int input = 0;
			cin >> input;
			int multiplier = 0;
			program.size(input, multiplier);
			break;

		case 2:
			cout << "������� ��������, �� ������� �� ������ �������� ������" << endl;
			cout << "�� x: ";
			cin >> s1;
			cout << "�� y: ";
			cin >> s2;
			program.move(s1, s2);
			break;

		case 3:

			break;

		case 4:

			break;

		case 5:
			flag = true;
			break;

		default:
			cout << "������!" << endl << "������� �������� �� 1 �� 5!" << endl;
		} */
	}
	system("pause");
	return 0;
}