#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("A.in", "r", stdin);
    freopen ("A2.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a+b == c+d || a+b == c-d)
			cout << a+b << "\n";
		else
			cout << a-b << "\n";
	}
}
