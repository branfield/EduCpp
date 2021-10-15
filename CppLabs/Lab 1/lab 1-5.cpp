#include <iostream> 
using namespace std;
int main()
{
	float a;
	cout << "Enter a = ";
	cin >> a;
	double n = 0, sum = 0;

	while (sum<a)
	{
		n++;
		sum = sum + (1 / n);
	}

	cout << "n = " << n;
	return 0;
}