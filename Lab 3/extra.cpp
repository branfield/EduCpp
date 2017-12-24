/* Вариант 1
Дан файл INPUT.txt. В нем записаны данные работников компании: ФИО, год рождения и зарплата. 
За один просмотр файла найдите ФИО и возраст самого высокооплачиваемого работника, который младше 35 лет. 
Ответ выведите в файл OUTPUT.txt 
Примечание: Возраст это разница текущего года 2017 и года рождения. */

//В ПРОЦЕССЕ//

#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Russian");
	ifstream fin("INPUT.TXT");
	ofstream fout("OUTPUT.TXT");
	int* mas = new int [255]; 
	if (!fin)
		cout << "Not Found";
	else
	{
		fin.getline(buff, 255);
		char* buff = new char[255];
	    	for (int i = 0; !fin.eof(); i++)
		{
			fin >> buff[i];
		}
		int a = atoi(tmp);
		if (!strchr(tmp, ';'))
					break;
			tmp = strchr(tmp, ' ') + 1;
		
		
		
		
	fin.close();
	fout.close();
	return 0;
}
