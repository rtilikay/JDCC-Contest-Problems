#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

double conv (string s, int b)
{
	double ans = 0;
	for (int i = 0; i < s.length (); i++)
	{
		if (s.at(i)-48 >= b)
			return -1;
		ans += pow (b, (s.length () - i - 1))*(s.at(i)-48);
	}
	return ans;
}

int main ()
{
    //freopen ("D.in", "r", stdin);
    //freopen ("D.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		string n, d;
		cin >> n >> d;
		int dd = stoi (d);
		double best = conv(n,max (10, dd-1))/conv(d, max (10, dd-1));
		for (int i = 2; i < dd; i++)
		{
			double tn = conv (n, i), td = conv (d, i);
			if (tn < 0 || td < 0)
				continue;
			best = max (best, tn/td);
			break;
		}
		printf ("%6f\n", best*100);
	}
}
