#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << "Enter a = ";
	cin >> a;
	int b, c, d, e;

	if (a>999)
	{
		b = int(a / 1000);
		c = int(a / 100) - b * 10;
		d = int(a / 10) - b * 100 - c * 10;
		e = a - b * 1000 - c * 100 - d * 10;
	}
	else if (a>99 && a<1000)
	{
		b = int(a / 100);
		c = int(a / 10) - b * 10;
		d = a - b * 100 - c * 10;
	}

	if ((b == c && c == d) || (b == c && c == e) || (b == d && d == e) || (c == d && d == e))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}