#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;

class Vector
{
	double x, y, scalar, lenght;

public:
	Vector() : x(0), y(0) {} //конструктор
	Vector(double x, double y) : x(x), y(y) {} //конструктор копирования

	Vector& operator = (const Vector& object) // присваивание
	{
		this->x = object.x;
		this->y = object.y;
		return *this;
	}

	Vector& operator+(const Vector& object) //перегрузка сложения векторов
	{
		Vector temp;
		temp.x = this->x + object.x;
		temp.y = this->y + object.y;
		return temp;
	}

	Vector& operator-(const Vector& object) //перегрузка вычитания векторов
	{
		Vector temp;
		temp.x = this->x - object.x;
		temp.y = this->y - object.y;
		return temp;
	}

	Vector& operator * (const Vector& object) //перегрузка умножения вектора на скаляр
	{
		Vector temp;
		temp.x = this->x * object.scalar;
		temp.y = this->y * object.scalar;
		return temp;
	}

	void vectorLenght() //длина вектора
	{
		lenght = sqrt(pow(x, 2) + pow(y, 2));
	}

	double getx()
	{
		return x;
	}

	int gety()
	{
		return y;
	}

	void setx(int x)
	{
		this->x;
	}

	void sety(int y)
	{
		this->y;
	}


	~Vector() {} //деструктор
};

int main()
{
	setlocale(0, "");
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Vector v1(0, 0);
	Vector v2(0, 0);
	Vector sum(0,0);
	Vector diff(0, 0);
	Vector multiplication(0, 0);
	int input = 0;
	double scalar = 0, lenght = 0;
	bool condition = true;
	while (true)
	{
		cout << "Выберите нужное действие: " << endl
			<< "(1) - сложение векторов" << endl
			<< "(2) - вычитание векторов" << endl
			<< "(3) - вычисление длины вектора" << endl
			<< "(4) - умножение вектора на скалярную величину" << endl
			<< "(5) - выйти из программы" << endl;

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


		case 2:
			cout << "Введите координаты первого вектора: " << endl << "x = ";
			cin >> x1;
			cout << endl << "y = ";
			cin >> y1;
			cout << "Введите координаты второго вектора: " << endl << "x = ";
			cin >> x2;
			cout << endl << "y = ";
			cin >> y2;
			v1 = Vector(x1, y1);
			v2 = Vector(x2, y2);
			diff = v1 - v2;

		case 3:
			cout << "Введите координаты вектора: " << endl << "x = ";
			cin >> x1;
			cout << "y = ";
			cin >> y1;
			v1 = Vector(x1, y1);
		/*	length = v1.vectorLenght();*/


		case 4:
			cout << "Введите координаты первого вектора: " << endl << "x = ";
			cin >> x1;
			cout << endl << "y = ";
			cin >> y1;
			cout << "Для продолжения требуется ввести скалярную величину: " << endl;
			cin >> scalar;
			v1 = Vector(x1, y1);
			/*multiplication = v1 * scalar;*/

		case 5:
			condition = false;
			break;

		default:
			cout << "Введите значение от 1 до 5!" << endl;
		}
	}
	system("pause");
	return 0;
}
