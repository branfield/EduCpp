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
		cout<<"Not Found";
	else
	{
		fin.getline(buff, 255);
		char* buff = new char[255];
	    for (int i = 0; !fin.eof(); i++)
		{
			fin >> buff[i];
		}
		
		
		
	fin.close();
	fout.close();
	return 0;
}
