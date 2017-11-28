#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
	char buff[50];
	ifstream fin("INPUT.TXT");

	if (!fin)
		cout<<"404";
	else
	{
		fin.getline(buff, 50);
		char* tmp = buff;
		int *mas = new int[50];
		for (int i = 0; i<50; i++)
		{
			int a = atoi(tmp);
			
			tmp = strchr(tmp, ' ') + 1;
			for (int i = 0; i<50; i++)
			{

			}
		}

	}

	ofstream fout;
	fout.open("OUTPUT.TXT");

	fin.close();
	fout.close();
	return 0;
}