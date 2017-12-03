/* 10 вариант.
В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк. 
За один просмотр файла сформировать список этих чисел. Определить количество
нулевых элементов в списке. Найденное число вставить в конец исходного списка. 
Полученный список занести в текстовый файл OUTPUT.TXT. */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
	char buff[50];
	ifstream fin("INPUT.TXT");
	ofstream fout;
	fout.open("OUTPUT.TXT");
	int count = 0;
	if (!fin)
		cout<<"Not Found";
	else
	{
		fin.getline(buff, 50);
		char* tmp = buff;
		int *mas = new int[50];
		for (int i = 0; i<50; i++)
		{
			int a = atoi(tmp);
			fout << a << " ";
			if (a == 0)
			count++;
			if (!strchr(tmp, ' '))
					break;
			tmp = strchr(tmp, ' ') + 1;
		}

	}

	fout << count;
	fin.close();
	fout.close();
	return 0;
}
