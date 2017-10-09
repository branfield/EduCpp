#include <iostream> 
using namespace std;
int main()
{
	float a, f;
	cout << "Enter a = ";
	cin >> a;
	if (a >= 0) {
		if (a<1) f = a;
		else if ((a >= 1) && (a <= 2)) f = 1;
		else if (a>2) f = 5 - 2 * a;

	}
	else f = -a;

	cout << "f(a) = " << f;
	return 0;
}