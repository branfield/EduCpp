#include <iostream>
#include <fstream>
#include<windows.h>
using namespace std;

template < class DataType >
class Stack
{
private:
	int count;

	struct Node
	{
		DataType data;
		Node* prev;
		Node* next;
	};

	Node* head;

public:

	~Stack()
	{
		while (count > 0)
		{
			Pop();
		}
	}

	int getCount() const { return count; }
	bool isEmpty() const { return !count; }

	void push(DataType data)
	{
		bool isFirst = true;
		if (isFirst)
		{
			isFirst = false;
			Node* node = new Node;
			node->next = nullptr;
			node->prev = nullptr;
			head->data = data;
		}
		else
		{
			Node* node = new Node;
			node->prev = head;
			head = node;

			head->data = data;
			node->prev->next = head;
			head->next = nullptr;
		}
	}

	DataType pop()
	{
		DataType resultData = head->data;
		auto willDeleted = head;

		if (count > 0)
		{
			if (count > 1)
			{
				head = head->prev;
				delete willDeleted;
			}
			else
			{
				delete head;
				head = nullptr;
			}
			count--;
			return resultData;
		}
		else
		{
			return nullptr;
		}
	}

	DataType* peek()
	{
		if (head) return head->data;
		return nullptr;
	}

	Node* getHead() { return head;  }
};

struct Coordinates
{
	int x;
	int y;
}; 


int check(Coordinates current, int **maze)
{
	if (maze[current.x][current.y] == 2)
		return(0);
	if (maze[current.x][current.y - 1] == 0 || maze[current.x][current.y - 1] == 2)
		return(1);
	if (maze[current.x - 1][current.y] == 0 || maze[current.x - 1][current.y] == 2)
		return(2);
	if (maze[current.x + 1][current.y] == 0 || maze[current.x + 1][current.y] == 2)
		return(3);
	if (maze[current.x][current.y + 1] == 0 || maze[current.x][current.y + 1] == 2)
		return(4);
}

template <class DataType>
void move(int value, Stack <DataType> stack, Coordinates &current)
{
	switch (value)
	{
	case(1):
		maze[current.x][current.y] = 2;
		current.y--;
		stack.push(current, stack.head);
		break;

	case(2):
		maze[current.x][current.y] = 2;
		current.x--;
		stack.push(current, stack.head);
		break;

	case(3):
		maze[current.x][current.y] = 2;
		current.x++;
		stack.push(current, stack.head);
		break;

	case(4):
		maze[current.x][current.y] = 2;
		current.y++;
		stack.push(current, stack.head);
		break;
	}
}

int** readMaze()
{
	int **maze;
	ifstream fin("input.txt");
	if (!fin)
		cout << "Лабиринт не найден!" << endl;
	else
	{
		int count = 0;
		int temp;

		while (!fin.eof())
		{
			fin >> temp;
			count++;
		}
		fin.seekg(0, ios::beg); 
		fin.clear();
		int count_space = 0;
		char symbol;
		while (!fin.eof())
		{
			fin.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}
		fin.seekg(0, ios::beg);
		fin.clear();
		int n = count / (count_space + 1);
		int m = count_space + 1;
		maze = new int*[n];
		for (int i = 0; i<n; i++) maze[i] = new int[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				fin >> maze[i][j];

		fin.close();
	}
	return maze;
}

void returnMaze(int **maze)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n";
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 1)
				cout << (char)219;
			else
				if (maze[i][j] == 2)
					cout << ".";
				else
					if ((maze[i][j] == 0))
						cout << (char)176;
					else
						cout << " ";
		}
	}
	cout << endl;
}

int main()
{
	setlocale(0, "");

	int** maze = readMaze();

	Stack <Coordinates> stack;
	Coordinates* curr = new Coordinates;
	curr->x = 12; curr->y = 19;
	stack.push(*curr);
	delete curr;

	while (check(*curr, maze))
	{
		returnMaze(maze);
		move(check(*stack.peek(), maze), stack, *curr);
	}
	returnMaze(maze);
	cout << endl;
	while (!(stack.getHead()->prev == nullptr))
	{
		stack.peek();
		stack.pop();
	}
	system("pause");
	return 0;
}