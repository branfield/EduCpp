#include <windows.h>
using namespace std;

class Rect
{
private:

	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

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

	void connection()
	{
		//Случаи, когда прямоугольники пересекаются
		if ((y3 < y1) && (y3 < y2) && (y2 < y4) && (x3 < x2) && (x3 > x1))
		{
			x3 = x1;
			y3 = y1;
		}
		else if ((y1 < y3) && (y1 < y4) && (y4 > y2) && (x1 < x4) && (x1 > x3) && (x4 < x2))
		{
			x4 = x2;
			y4 = y2;
		}
		else if ((x1<x3) && (x2<x4) && (x2>x3) && (y3>y1) && (y1>y4) && (y2<y4))
		{
			x3 = x1;
			y4 = y2;
		}
		else if ((x3 < x1) && (x4 > x2) && (x1 < x4) && (y3 < y1) && (y3 > y4) && (y2 > y4))
		{
			y3 = y1;
			x4 = x2;
		}
		//Случай, когда прямоугольники совпадают
		else if ((x1 = x3) && (x2 = x4) && (y1 = y3) && (y1 = y4))
		{
			x3 = x1;
			y3 = y1;
			x4 = x2;
			y4 = y2;
		}
		//Случаи, когда прямоугольники НЕ пересекаются
		//Случаи, когда один прямоугольник находится внутри другого
	}

	void leastUnion()
	{
		//Случаи, когда прямоугольники пересекаются
		if ((y3 < y1) && (y3 < y2) && (y2 < y4) && (x3 < x2) && (x3 > x1))
		{
			x4 = x2;
			y4 = y2;
		}
		if ((y1 < y3) && (y1 < y4) && (y4 > y2) && (x1 < x4) && (x1 > x3) && (x4 < x2))
		{
			x3 = x1;
			y3 = y1;
		}
		else if ((x1<x3) && (x2<x4) && (x2>x3) && (y3>y1) && (y1>y4) && (y2<y4))
		{
			y3 = y1;
			x4 = x2;
		}
		else if ((x3 < x1) && (x4 > x2) && (x1 < x4) && (y3 < y1) && (y3 > y4) && (y2 > y4))
		{
			x3 = x1;
			y4 = y2;
		}
		//Случай, когда прямоугольники совпадают
		else if ((x1 = x3) && (x2 = x4) && (y1 = y3) && (y1 = y4))
		{
			x3 = x1;
			y3 = y1;
			x4 = x2;
			y4 = y2;
		}
		//Случаи, когда прямоугольники НЕ пересекаются
		//Случаи, когда один прямоугольник находится внутри другого
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
			cout << "Ошибка ввода. Введите число. " << endl;
			break;
		}
		else
		{
			return atoi(buff);
			flag = false;
			break;
		}
	}
}

int main()
{
	setlocale(0, "");
	cout << "Для начала работы требуется ввести координаты прямоугольника. " << endl;
	bool condition = false;
	char* x1 = new char;
	char* y1 = new char;
	char* x2 = new char;
	char* y2 = new char;

	while (!condition)
	{
		cout << "Введите координаты верхней левой точки: " << endl;
		cout << "x = ";
		cin >> x1;
		FoolProtection(x1);

		cout << "y = ";
		cin >> y1;
		FoolProtection(y1);

		cout << "Введите координаты нижней правой точки: " << endl;

		cout << "x = ";
		cin >> x2;
		FoolProtection(x2);

		cout << "y = ";
		cin >> y2;
		FoolProtection(y2);

		int height = 0, widht = 0;
		height = y1 - y2;
		widht = x2 - x1;
		if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
		else condition = true;
	}
	Rect program(x1, y1, x2, y2);

	bool flag = false;
	int input = 0;
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
			bool flag1 = false;
			int input1 = 0;
			int addendum = 0;
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
					program.moveRight(addendum);
					break;

				case 2:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					program.moveLeft(addendum);
					break;

				case 3:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					cin >> addendum;
					program.moveUp(addendum);
					break;

				case 4:
					cout << "На какое значение Вы хотите сместить фигуру? " << endl;
					program.moveDown(addendum);
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
			bool flag2 = false;
			int input2 = 0;
			int multiplier = 0;
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
					program.sizeIncrease(multiplier);
					break;

				case 2:
					cout << "Во сколько раз Вы хотите уменьшить фигуру? " << endl;
					cin >> multiplier;
					program.sizeReduce(multiplier);
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
			bool flag3 = false;
			while (!flag3)
			{
			cout << "Введите координаты верхней левой точки: " << endl;

			char* x3 = new char;
			cout << "x = ";
			cin >> x3;
			FoolProtection(x3);

			char* y3 = new char;
			cout << "y = ";
			cin >> y3;
			FoolProtection(y3);

			cout << "Введите координаты нижней правой точки: " << endl;

			char* x4 = new char;
			cout << "x = ";
			cin >> x4;
			FoolProtection(x4);

			char* y4 = new char;
			cout << "y = ";
			cin >> y4;
			FoolProtection(y4);

			int height = 0, widht = 0;
			height = y1 - y2;
			widht = x2 - x1;
			if ((height <= 0) || (widht <= 0)) cout << "Полученная фигура не является прямоугольником, повторите ввод " << endl;
			else flag3 = true;
			}

			cout << "Наименьший полученный прямоугольник имеет координаты: " << endl;
			cout << " x1 = " << x3 << endl;
			cout << "y1 = " << y3 << endl;
			cout << "x2 = " << x4 << endl;
			cout << "y2 = " << y4 << endl;

			case 4:

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
