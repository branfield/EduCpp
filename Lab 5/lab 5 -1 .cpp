#include<iostream>
#include <windows.h>
using namespace std;

class Rect
{
	int x1, y1, x2, y2;
	int abs0, ord0, abs, ord; //для output 

public:

	Rect(int abs1, int ord1, int abs2, int ord2)
	{
		this->x1 = abs1;
		this->y1 = ord1;
		this->x2 = abs2;
		this->y2 = ord2;
	}

	void sizeIncrease(int temp)
	{
		abs0 = x1 * temp;
		ord0 = y1 * temp;
		abs = x2 * temp;
		ord = y2 * temp;
	}

	void sizeReduce(int temp)
	{
		abs0 = x1 / temp;
		ord0 = y1 / temp;
		abs = x2 / temp;
		ord = y2 / temp;
	}

	void moveRight(int temp)
	{
		abs0 = x1 + temp;
		abs = x2 + temp;
		ord0 = y1;
		ord = y2;
	}

	void moveLeft(int temp)
	{
		abs0 = x1 - temp;
		abs = x2 - temp;
		ord0 = y1;
		ord = y2;
	}

	void moveUp(int temp)
	{
		abs0 = x1;
		abs = x2;
		ord0 = y1 + temp;
		ord = y2 + temp;
	}

	void moveDown(int temp)
	{
		abs0 = x1;
		abs = x2;
		ord0 = y1 - temp;
		ord = y2 - temp;
	}

	void leastUnion(Rect* rect)
	{
		int X = 0, Y = 0, x = 0, y = 0;
		int r1[4] = {this->getx1(), this->gety1(), this->getx2(), this->gety2()};
		int r2[4] = { x1, y1, x2, y2 };
		for (int i = 0; i < 4; i++)
		{
			if (X < r1[i])
			{
				X = r1[i];
			}
			if (Y < r2[i])
			{
				Y = r2[i];
			}
			if (x > r1[i])
			{
				x = r1[i];
			}
			if (y > r2[i])
			{
				y = r2[i];
			}
		}

		abs0 = x;
		ord0 = Y;
		abs = X;
		ord = y;
	}

	void connection(Rect* rect)
	{
		int X = 0, Y = 0, x = 0, y = 0;
		int middlex1 = 0, middlex2 = 0, middley1 = 0, middley2 = 0;
		int r1[4] = { this->getx1(), this->gety1(), this->getx2(), this->gety2() };
		int r2[4] = { x1, y1, x2, y2 };
		for (int i = 0; i < 4; i++)
		{
			if (X < r1[i])
			{
				X = r1[i];
			}
			if (Y < r2[i])
			{
				Y = r2[i];
			}
			if (x > r1[i])
			{
				x = r1[i];
			}
			if (y > r2[i])
			{
				y = r2[i];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((r1[i] != X) && (r1[i] != x))
			{
				middlex1 = r1[i];
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((r1[i] != X) && (r1[i] != x) && (r1[i] != middlex1))
			{
				middlex2 = r1[i];
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((r2[i] != Y) && (r2[i] != y))
			{
				middley1 = r2[i];
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((r2[i] != Y) && (r2[i] != y) && (r2[i] != middley1))
			{
				middley2 = r2[i];
				break;
			}
		}

		abs0 = middlex1;
		ord0 = middley2;
		abs = middlex2;
		ord = middley1;
	}

	int getabs0() { return abs0; }
	int getord0() { return ord0; }
	int getabs() { return abs; }
	int getord() { return ord; }
	int getx1() { return x1; }
	int gety1() { return y1; }
	int getx2() { return x2; }
	int gety2() { return y2; }

};

void menu()
{
	cout << endl << "Выберите нужное действие: " << endl << endl;
	cout << "(1) — перемещение фигуры на плоскости" << endl;
	cout << "(2) — изменение размера фигуры" << endl;
	cout << "(3) — построение наименьшего прямоугольника, содержащего два заданных прямоугольника" << endl;
	cout << "(4) — построение наименьшего прямоугольника, являющегося пересечением двух заданных прямоугольников" << endl;
	cout << "(5) — выход из программы" << endl;
}

int FoolProtection()
{
	char* buff = new char[256];
	bool flag = true;
	while (true)
	{
		cin >> buff;
		for (int i = 0; i < strlen(buff); i++)
		{
			if (buff[0] == '-')
			{
				buff[0] = '-';
				i++;
			}
			if ((buff[i] >= '0' && buff[i] <= '9'))
			{
				flag = false;
				return atoi(buff);
			}
			else cout << "Ошибка! Введите число!" << endl;
			break;
		}
	}
}

bool checkForARectangle(int x1, int y1, int x2, int y2)
{
	bool flag = true;
	int height = 0, widht = 0;
	height = y1 - y2;
	widht = x2 - x1;
	if ((height <= 0) || (widht <= 0))
	{
		cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl << endl;
		return 1;
	}
	else return 0;
}

void building(int& x1, int& y1, int& x2, int& y2)
{
	while (checkForARectangle)
	{
		cout << "Введите координаты верхней левой точки: " << endl;
		cout << "x = ";
		x1 = FoolProtection();

		cout << "y = ";
		y1 = FoolProtection();

		cout << endl << "Введите координаты нижней правой точки: " << endl;
		cout << "x = ";
		x2 = FoolProtection();

		cout << "y = ";
		y2 = FoolProtection();
		
		if (!checkForARectangle(x1, y1, x2, y2))
			break;
	}
}

int move()
{
	int value = 0;
	cout << "На какое значение Вы хотите сместить фигуру? " << endl;
	cin >> value;
	return value;
}

int resize()
{
	int value = 0;
	cout << "Во сколько раз Вы хотите увеличить фигуру? " << endl;
	cin >> value;
	return value;
}

void output(Rect* r)
{
	cout << endl <<  "Полученные значения: " << endl;
	cout << "x1 = " << r->getabs0() << endl;
	cout << "y1 = " << r->getord0() << endl;
	cout << "x2 = " << r->getabs() << endl;
	cout << "y2 = " << r->getord() << endl;
}

int main()
{
	setlocale(0, "");

	Rect* r1 = new Rect(0, 0, 0, 0);
	Rect* r2 = new Rect(0, 0, 0, 0);

	cout << "Для начала работы требуется ввести координаты прямоугольника. " << endl;

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	building(x1, y1, x2, y2); //вызов функции построения основного прямоугольника
	r1 = new Rect(x1, y1, x2, y2);

	bool condition = false, flag1 = false, flag2 = false;
	int input = 0, input1 = 0, input2 = 0;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	int digit = 0;

	while (!condition)
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1: //перемещение в плоскости
			while (!flag1)
			{
				cout << "(1) — переместить фигуру вправо " << endl;
				cout << "(2) — переместить фигуру влево " << endl;
				cout << "(3) — переместить фигуру вверх " << endl;
				cout << "(4) — переместить фигуру вниз " << endl;
				cout << "(5) — вернуться в меню " << endl;
				cin >> input1;

				if (input >= 1 && input <= 4)
					digit = move();

				switch (input1)
				{
				case 1: //вправо
					r1->moveRight(digit);
					output(r1);
					break;

				case 2: //влево
					r1->moveLeft(digit);
					output(r1);
					break;

				case 3: //вверх
					r1->moveUp(digit);
					output(r1);
					break;

				case 4: //вниз
					r1->moveDown(digit);
					output(r1);
					break;

				case 5:
					flag1 = true;
					break;

				default:
					cout << "Введите значение от 1 до 5 " << endl;

				} break;
			} break;

		case 2: //изменение размеров
			while (!flag2)
			{
				cout << "(1) — увеличить фигуру " << endl;
				cout << "(2) — уменьшить фигуру " << endl;
				cout << "(3) — вернуться в меню " << endl;
				cin >> input2;

				if (input >= 1 && input <= 4)
					digit = resize();

				switch (input2)
				{
				case 1: //увеличение
					r1->sizeReduce(digit);
					output(r1);
					break;

				case 2: //уменьшение
					r1->sizeIncrease(digit);
					output(r1);
					break;

				case 3:
					flag2 = true;
					break;

				default:
					cout << "Введите значение от 1 до 3" << endl;
					break;
				} break;
			} break;

		case 3: //построение наименьшего, содержащего два заданных
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			building(x3, y3, x4, y4); //построение второго прямоугольника
			r2 = new Rect(x3, y3, x4, y4);
			r1->leastUnion(r2);
			output(r2);
			break;


		case 4: //объединение двух прямоугольников
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			building(x3, y3, x4, y4); //построение второго прямоугольника
			r2 = new Rect(x3, y3, x4, y4);
			r1->connection(r2);
			output(r2);
			break;

		case 5:
			system("pause");
			return 0;

		default:
			cout << "Введите значение от 1 до 5 " << endl;
		}
	}
}
