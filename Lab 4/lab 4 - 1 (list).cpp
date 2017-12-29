/* ВАРИАНТ 2. 
• реализовать вторую версию программы, вместо массива использовать двусвязный список;
элементы добавлять таким образом, чтобы сохранялась упорядоченность списка по номеру рейса
(вставка нового элемента после элемента, который меньше нового элемента и перед большим элементом). */

#include <iostream> 
#include <cstdlib> 
#include <cstring> 
using namespace std;

struct aeroflot
{
	char *name;
	short number;
	char *type;
};

struct list
{
	struct cell
	{
		aeroflot data;

		cell *next;
		cell *prev;
	};
	cell *head = nullptr;

	void add(aeroflot info)
	{
		cell *temp = new cell;
		temp->data = info;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = temp;
			return;
		}

		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void print()
	{
		cell *temp = head;
		while (temp != nullptr)
		{
			cout << "Название пункта назначения: " << temp->data.name << endl;
			cout << "Номер рейса: " << temp->data.number << endl;
			cout << "Тип самолета: " << temp->data.type << endl << endl;

			temp = temp->next;
		}
	}

	void clear()
	{
		while (head != nullptr)
		{
			delete[] head->data.name;
			delete[] head->data.number;
			delete[] head->data.type;
			cell *temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int fool_protection(int *buff)
{
	while (1)
	{
		cin >> buff;
		bool q = true;
		for (int i = 0; i < strlen(buff); i++)
			if (buff[i] < '0' || buff[i] > '9')
			{
				q = false;
				break;
			}

		if (!q)
			cout << "Ошибка! Введите число! " << endl;
		else
		{
			return *buff;
			delete buff;
			break;
		}
	}
}

int main()
{
	setlocale(0, "");
	list a;
	for (int i = 0; i < 7; i++)
	{
		aeroflot b;

		char* buff = new char[255];
		cout << i << ".  Пункт назначения рейса: ";
		cin >> buff;
		int n = strlen(buff) + 1;
		info.name = new char[n];
		strcpy(info.name, buff);
		info.name[n] = '\0';

		cout << i << ". Номер рейса: ";
		buff.info = fool_protection();
		cin >> info.number;

		cout << i << ". Тип самолета: ";
		cin >> buff;
		info.name = new char[n];
		strcpy(info.type, buff);
		info.type[n] = '\0';

		list.add(b);
	}
	list.print();
	list.clear();
	system("pause");
	return 0;
}