#include <iostream>
#include <windows.h>
using namespace std;

class Rectangles
{
public:
	int x1, y1, x2, y2;

	void constructor()
	{
		cout << "Введите координаты верхней левой точки: " << endl;
		cout << "абсцисса = ";
		cin >> x1;
		cout << "ордината = ";
		cin >> y1;

		cout << "Введите координаты нижней правой точки: " << endl;
		cout << "абсцисса = ";
		cin >> x2;
		cout << "ордината = ";
		cin >> y2;
	}

	void move()
	{
		int input = 0, addendum = 0;
		bool flag = false;
		while (!flag)
		{
			cout << "По какой оси Вы хотите сдвинуть фигуру? " << endl;
			cout << "(1) — по оси абсцисс" << endl << "(2) — по оси ординат" << endl << "(3) — окончание процесса" << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				cout << "Введите значение, на которое Вы хотите сдвинуть фигуру: ";
				cin >> addendum;
				x1 += addendum;
				x2 += addendum;
				break;

			case 2:
				cout << "Введите значение, на которое Вы хотите сдвинуть фигуру: ";
				cin >> addendum;
				y1 += addendum;
				y2 += addendum;
				break;

			case 3:
				flag = true;
				break;

			default:
				cout << "Ошибка!" << endl << "Введите значение от 1 до 3!" << endl;
			}
		}
	}

	void size()
	{
		bool flag = false;
		while (!flag)
		{
			cout << "Выберите нужное действие для продолжения" << endl;
			cout << "(1) — увеличить" << endl << "(2) — уменьшить" << endl << "(3) — выход в меню" << endl;
			int input = 0, multiplier = 0;
			cin >> input;
			switch (input)
			{
			case 1:
				cout << "Во сколько раз Вы хотите увеличить фигуру?" << endl;
				cin >> multiplier;
				x1 *= multiplier;
				x2 *= multiplier;
				y1 *= multiplier;
				y2 *= multiplier;
				break;

			case 2:
				cout << "Во сколько раз Вы хотите уменьшить фигуру?" << endl;
				cin >> multiplier;
				x1 /= multiplier;
				x2 /= multiplier;
				y1 /= multiplier;
				y2 /= multiplier;
				break;

			case 3:
				flag = true;
				break;

			default:
				cout << "Ошибка!" << endl << "Введите значение от 1 до 3!" << endl;
			}
		}
	}

	void connection()
	{
		int x3 = x1;
		int y3 = y1;
		int x4 = x2;
		int y4 = y2;
		cout << "Действие требует дополнительного ввода значений" << endl;
		constructor();
		if (x3 > x1)
		{
			x2 = x4;
			y2 = y4;
		}
		else
		{
			x1 = x3;
			y1 = y3;
		}
	}

	void leastUnion()
	{
		int x3 = x1;
		int y3 = y1;
		int x4 = x2;
		int y4 = y2;
		cout << "Действие требует дополнительного ввода значений" << endl;
		constructor();
	}

	void output()
	{
		cout << endl << "Полученные значения:" << endl;
		cout << "абсцисса верхней левой точки = " << x1 << endl;
		cout << "ордината верхней левой точки = " << y1 << endl;
		cout << "абсцисса нижней правой точки = " << x2 << endl;
		cout << "ордината нижней правой точки = " << y2 << endl;
	}
};

int main()
{
	setlocale(0, "");
	Rectangles program;
	program.constructor();
	bool flag = false;
	while (!flag)
	{
		cout << endl << endl << "Выберите нужное действие: " << endl;
		cout << "(1) — перемещение фигуры на плоскости" << endl;
		cout << "(2) — изменение размера фигуры" << endl;
		cout << "(3) — построение наименьшего прямоугольника, содержащего два заданных прямоугольника" << endl;
		cout << "(4) — построение наименьшего прямоугольника, являющегося пересечением двух заданных прямоугольника" << endl;
		cout << "(5) — выход" << endl;

		int e;
		cout << endl;
		cin >> e;

		switch (e)
		{
		case 1:
			program.move();
			program.output();
			break;

		case 2:
			program.size();
			program.output();
			break;

		case 3:
			program.connection();
			program.output();
			break;

		case 4:
			program.leastUnion();
			program.output();
			break;

		case 5:
			flag = true;
			break;

		default:
			cout << "Ошибка!" << endl << "Введите значение от 1 до 5!" << endl;
		}
	}
	return 0;
}
