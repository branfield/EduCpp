#include<iostream>
#include <windows.h>
using namespace std;

class Rect
{
private:

	int x1, y1, x2, y2;

public:

	Rect(int abs1, int ord1, int abs2, int ord2)
	{
		this->x1 = abs1;
		this->y1 = ord1;
		this->x2 = abs2;
		this->y2 = ord2;
	}

	void sizeIncrease(int multiplier)
	{
		x1 *= multiplier;
		y1 *= multiplier;
		x2 *= multiplier;
		y2 *= multiplier;
	}

	void sizeReduce(int multiplier)
	{
		x1 /= multiplier;
		y1 /= multiplier;
		x2 /= multiplier;
		y2 /= multiplier;
	}

	void moveRight(int addendum)
	{
		x1 += addendum;
		x2 += addendum;
	}

	void moveLeft(int addendum)
	{
		x1 -= addendum;
		x2 -= addendum;
	}

	void moveUp(int addendum)
	{
		y1 += addendum;
		y2 += addendum;
	}

	void moveDown(int addendum)
	{
		y1 -= addendum;
		y2 -= addendum;
	}

	void get(int abs, int ord, int abs0, int ord0)
	{
		abs = x1;
		ord = y1;
		abs0 = x2;
		ord0 = y2;
	}

	int getx1()
	{
		return x1;
	}

	int gety1()
	{
		return y1;
	}

	int getx2()
	{
		return x2;
	}

	int gety2()
	{
		return y2;
	}

	~Rect()
	{
	}
};

void leastUnion(Rect figure1, Rect figure2)
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
	figure1.get(x1, y1, x2, y2);
	figure2.get(x3, y3, x4, y4);

	//Случаи, когда прямоугольники пересекаются
	if ((x3 > x1) && (x2 > x3) && (y1 >= y3) && (y3 <= y2))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if ((x3 < x1) && (x1 < x4) && (y3 >= y1) && (y1 >= y4))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}
	else if ((x3 > x1) && (x4 > x2) && (y3 > y1) && (y1 < y4))
	{
		X1 = x1;
		Y1 = y3;
		X2 = x4;
		Y2 = y2;
	}
	else if ((x1>x3) && (x4>x1) && (y1>y3) && (y3>y2))
	{
		X1 = x3;
		Y1 = y1;
		X2 = x2;
		Y2 = y4;
	}

	//Случай, когда один прямоугольник находится внутри другого или совпадает с ним
	else if (((x3 >= x1) && (x4 <= x2) && (y3 <= y1) && (y4 >= y2)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x4;
		Y2 = y4;
	}
	else if (((x1 >= x3) && (x2 <= x4) && (y1 <= y3) && (y2 >= y4)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;
	}

	//Случаи, когда прямоугольники НЕ пересекаются
	else if (((y2 > y3) && (y1 < y4)) || ((x2 < x3) && (x1 < x4)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if (((y4 < y1) && (y3 < y2)) || ((x4 < x1) && (x3 < x2)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}

	cout << "Полученные значения: " << endl;
	cout << "Верхняя левая точка: " << endl;
	cout << "x = " << X1 << endl;
	cout << "y = " << Y1 << endl;
	cout << "Нижняя правая точка: " << endl;
	cout << "x = " << X2 << endl;
	cout << "y = " << Y2 << endl; 
}

void connection(Rect figure1, Rect figure2)
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
	figure1.get(x1, y1, x2, y2);
	figure2.get(x3, y3, x4, y4);

	//Случаи, когда прямоугольники НЕ пересекаются
	 if ((y2 > y3) && (y1 < y4))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((y4 < y1) && (y3 < y2))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((x2 < x3) && (x1 < x4))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}
	else if ((x4 < x1) && (x3 < x2))
	{
		cout << "Такого прямоугольника не существует!" << endl;
	}

	//Случаи, когда прямоугольники пересекаются
	else if ((x3 > x1) && (x2 > x3) && (y1 >= y3) && (y3 <= y2))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x2;
		Y2 = y2;
	}
	else if ((x3 < x1) && (x1 < x4) && (y3 >= y1) && (y1 >= y4))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x4;
		Y2 = y4;
	}
	else if ((x3 > x1) && (x4 > x2) && (y3 > y1) && (y1 < y4))
	{
		X1 = x3;
		Y1 = y1;
		X2 = x2;
		Y2 = y4;
	}
	else if ((x1>x3)&&(x4>x1)&&(y1>y3)&&(y3>y2))
	{
		X1 = x1;
		Y1 = y3;
		X2 = x4;
		Y2 = y2;
	}

	//Случай, когда один прямоугольник находится внутри другого или совпадает с ним
	else if (((x3 >= x1) && (x4 <= x2) && (y3 <= y1) && (y4 >= y2)))
	{
		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;
	}
	else if (((x1 >= x3) && (x2 <= x4) && (y1 <= y3) && (y2 >= y4)))
	{
		X1 = x3;
		Y1 = y3;
		X2 = x4;
		Y2 = y4;
	}

	cout << "Полученные значения: " << endl;
	cout << "Верхняя левая точка: " << endl;
	cout << "x = " << X1 << endl;
	cout << "y = " << Y1 << endl;
	cout << "Нижняя правая точка: " << endl;
	cout << "x = " << X2 << endl;
	cout << "y = " << Y2 << endl;
}


int FoolProtection(char* buff = new char)
{
	bool flag = true;
	while (true)
	{
		bool normal = true;
		for (int i = 0; i < strlen(buff); i++)
		{
			if (buff[0] == '-') i++;
			if (buff[i] < '0' || buff[i] > '9')
			{
				normal = false;
				break;
			}
		}

		if (!normal)
		{
			return -1;
		}
		else
		{
			return atoi(buff);
			flag = false;
			break;
		}
	}
}

bool set(char* buff, int a)
{
	cin >> buff;
	if (FoolProtection(buff) == -1)
	{
		cout << "Ошибка ввода. Введите число. " << endl;
		return 0;
	}
	else
	{
		a = FoolProtection(buff);
		return 1;
	}
}


int main()
{
	setlocale(0, "");
	cout << "Для начала работы требуется ввести координаты прямоугольника. " << endl;
	bool condition = false;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	char* abs1 = new char;
	char* ord1 = new char;
	char* abs2 = new char;
	char* ord2 = new char;
	bool smth = true;

	Rect* r1 = new Rect (0,0,0,0);

	while (!condition)
	{
		cout << "Введите координаты верхней левой точки: " << endl;

		do 
		{
			if (set(abs1, x1) == 0)
			{
				cout << "x = ";
				set(abs1, x1);
			}
			else
			{
				smth = false;
				break;
			}
		}
		while (true);

		
		cout << "y = ";
		set(ord1, y1);

		cout << "Введите координаты нижней правой точки: " << endl;
		cout << "x = ";
		set(abs2, x2);

		cout << "y = ";
		set(ord2, y2);

		*r1 = Rect(x1, y1, x2, y2);
		r1->getx1();
		r1->getx2();
		r1->gety1();
		r1->gety2();

		int height = 0, widht = 0;
		height = abs(r1->gety1() - r1->gety2());
		widht = abs((r1->getx2() - r1->getx1()));
		if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
		else condition = true;
	}


	bool flag = false;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	int input = 0, input1 = 0, input2 = 0;
	int addendum = 0, multiplier = 0;

	Rect* r2 = new Rect(0, 0, 0, 0);
	Rect* r3 = new Rect(0, 0, 0, 0);

	while (!flag)
	{
		cout << "Выберите нужное действие: " << endl << endl;
		cout << "(1) — перемещение фигуры на плоскости" << endl;
		cout << "(2) — изменение размера фигуры" << endl;
		cout << "(3) — построение наименьшего прямоугольника, содержащего два заданных прямоугольника" << endl;
		cout << "(4) — построение наименьшего прямоугольника, являющегося пересечением двух заданных прямоугольника" << endl;
		cout << "(5) — выход из программы" << endl;

		cin >> input;

		switch (input)
		{
		case 1:
			while (!flag1)
			{
				cout << "(1) — переместить фигуру вправо " << endl;
				cout << "(2) — переместить фигуру влево " << endl;
				cout << "(3) — переместить фигуру вверх " << endl;
				cout << "(4) — переместить фигуру вниз " << endl;
				cout << "(5) — вернуться в меню " << endl;
				cin >> input1;

				switch (input1)
				{
				case 1:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveRight(addendum);
					break;

				case 2:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveLeft(addendum);
					break;

				case 3:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					r1->moveUp(addendum);
					break;

				case 4:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					r1->moveDown(addendum);
					cin >> addendum;
					break;

				case 5:
					flag1 = true;
					break;

				default:
					cout << "Введите значение от 1 до 5 " << endl;
				}
			}

		case 2:
			while (!flag2)
			{
				cout << "(1) — увеличить фигуру " << endl;
				cout << "(2) — уменьшить фигуру " << endl;
				cout << "(3) — вернуться в меню " << endl;
				cin >> input2;

				switch (input2)
				{
				case 1:
					cout << "Во сколько раз Вы хотите увеличить фигуру? " << endl;
					cin >> multiplier;
					r1->sizeIncrease(multiplier);
					break;

				case 2:
					cout << "Во сколько раз Вы хотите уменьшить фигуру? " << endl;
					cin >> multiplier;
					r1->sizeReduce(multiplier);
					break;

				case 3:
					flag2 = true;
					break;

				default:
					cout << "Введите значение от 1 до 3" << endl;
					break;
				}
			}

		case 3:
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			while (!condition)
			{
				cout << "Введите координаты верхней левой точки: " << endl;
				cout << "x = ";
				set(abs1, x1);

				cout << "y = ";
				set(ord1, y1);

				cout << "Введите координаты нижней правой точки: " << endl;
				cout << "x = ";
				set(abs2, x2);

				cout << "y = ";
				set(ord2, y2);

				int height = abs(y1 - y2);
				int widht = abs(x2 - x1);
				if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
				else condition = true;
			}
			*r2 = Rect(x1, y1, x2, y2); 
			connection(*r1, *r2);
			

		case 4:
			cout << "Для продолжения работы требуется второй прямоугольник" << endl;
			while (!condition)
			{
				cout << "Введите координаты верхней левой точки: " << endl;
				cout << "x = ";
				set(abs1, x1);

				cout << "y = ";
				set(ord1, y1);

				cout << "Введите координаты нижней правой точки: " << endl;
				cout << "x = ";
				set(abs2, x2);

				cout << "y = ";
				set(ord2, y2);

				int height = abs(y1 - y2);
				int widht = abs(x2 - x1);
				if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
				else condition = true;
			}
			*r3 = Rect(x1, y1, x2, y2);

		case 5:
			flag = true;
			break;

		default:
			cout << "Введите значение от 1 до 5 " << endl;
		}
	}
	system("pause");
	return 0;
}
