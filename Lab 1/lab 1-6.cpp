#include <iostream> 
#include <cmath> 
using namespace std;
int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	float x;
	cout << "Enter x = ";
	cin >> x;
	float pr = 1;
	int i = 1;
	while (i != n)
	{
		pr = pr*(x + cos(i*x) / pow(2, i));
		i++;
	}
	cout << "Answer = " << pr;
	return 0;
}