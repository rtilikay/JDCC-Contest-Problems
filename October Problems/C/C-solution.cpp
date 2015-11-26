#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int n;
		cin >> n;
		double marks [n], average = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> marks[i];
			average += marks[i];
		}
		average = average / n;
		double offset = 50.0 - average;
		int count = 0;
		for (int i = 0; i < n; i++)
			if (marks[i] + offset >= 50.0)
				count++;
		cout << count << "\n";
	}
}
