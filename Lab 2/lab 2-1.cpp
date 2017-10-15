#include <iostream> 
#include <cmath> 
using namespace std;
int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	float *mas = new float[n];
	float sum = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> mas[i];
		sum = sum + mas[i];
	}

	int sr;
	sr = sum / n;
	int min, k;
	min = mas[1];
	for (i = 0; i < n; i++)
	{
		if (mas[i] < min)
		{
			min = mas[i];
			k = i;
			mas[k] = sr;
		}

		if (mas[i] == min)
		{
			mas[0] = sr;
			mas[n] = sr;
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	system("pause");
	return 0;
}