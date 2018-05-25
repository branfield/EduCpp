#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;

class Vector
{
	double x, y, lenght;

public:
	Vector() : x(0), y(0) {} //конструктор
	Vector(double x, double y) : x(x), y(y) {} //конструктор копирования

	Vector operator = (const Vector& object) // перегрузка присваивания
	{
		this->x = object.x;
		this->y = object.y;
		return *this;
	}

	Vector operator+(const Vector& object) //перегрузка сложения векторов
	{
		Vector temp;
		temp.x = this->x + object.x;
		temp.y = this->y + object.y;
		return temp;
	}

	Vector operator-(const Vector& object) //перегрузка вычитания векторов
	{
		Vector temp;
		temp.x = this->x - object.x;
		temp.y = this->y - object.y;
		return temp;
	}

	Vector operator * (const double& scalar) //перегрузка умножения вектора на скаляр
	{
		Vector temp;
		temp.x = this->x * scalar;
		temp.y = this->y * scalar;
		return temp;
	}

	double vectorLenght() //длина вектора
	{
		lenght = sqrt(pow(x, 2) + pow(y, 2));
		return lenght;
	}

	double getx() { return x; }
	double gety() { return y; }
	double getlenght() { return lenght;  }
	void setx(int x) { this->x; }
	void sety(int y) { this->y; }
};

void menu()
{
	cout << "Выберите нужное действие: " << endl
		<< "(1) - сложение векторов" << endl
		<< "(2) - вычитание векторов" << endl
		<< "(3) - вычисление длины вектора" << endl
		<< "(4) - умножение вектора на скалярную величину" << endl
		<< "(5) - выйти из программы" << endl;
}

int main()
{
	setlocale(0, "");
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Vector v1(0, 0), v2(0, 0),sum(0, 0), diff(0, 0), multiplication(0, 0);
	int input = 0;
	double scalar = 0, length = 0;
	bool condition = true;
	while (true)
	{
		menu();

		cin >> input;
		switch (input)
		{
		case 1:
			cout << "Введите координаты первого вектора: " << endl << "x = ";
			cin >> x1;
			cout << "y = ";
			cin >> y1;
			cout << "Введите координаты второго вектора: " << endl << "x = ";
			cin >> x2;
			cout << "y = ";
			cin >> y2;
			v1 = Vector(x1, y1);
			v2 = Vector(x2, y2);
			sum = v1 + v2;
			cout << "x =" << sum.getx() << endl;
			cout << "y = " << sum.gety() << endl;
			break;

		case 2:
			cout << "Введите координаты первого вектора: " << endl << "x = ";
			cin >> x1;
			cout << "y = ";
			cin >> y1;
			cout << "Введите координаты второго вектора: " << endl << "x = ";
			cin >> x2;
			cout << endl << "y = ";
			cin >> y2;
			v1 = Vector(x1, y1);
			v2 = Vector(x2, y2);
			diff = v1 - v2;
			cout << "x = " << diff.getx() << endl;
			cout << "y = " << diff.gety() << endl;
			break;

		case 3:
			cout << "Введите координаты вектора: " << endl << "x = ";
			cin >> x1;
			cout << "y = ";
			cin >> y1;
			v1 = Vector(x1, y1);
			length = v1.vectorLenght();
			cout << "длина вектора = " << v1.getlenght() << endl;
			break;


		case 4:
			cout << "Введите координаты первого вектора: " << endl << "x = ";
			cin >> x1;
			cout <<  "y = ";
			cin >> y1;
			cout << "Для продолжения требуется ввести скалярную величину: " << endl;
			cin >> scalar;
			v1 = Vector(x1, y1);
			multiplication = v1 * scalar;
			cout << "x = " << multiplication.getx() << endl;
			cout << "y = " << multiplication.gety() << endl;
			break;

		case 5:
			condition = false;
			system("pause");
			return 0;

		default:
			cout << "Введите значение от 1 до 5!" << endl;
			break;
		}
	}
}
