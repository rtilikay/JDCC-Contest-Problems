#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main ()
{
    freopen ("B.in", "r", stdin);
    freopen ("B.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int n;
		cin >> n;
		string male = "", female = "";
		int maleBest = 0, femaleBest = 0;
		for (int i = 0; i < n; i++)
		{
			string s;
			int t;
			char c;
			cin >> s >> c >> t;
			if (c == 'M')
			{
				if (t > maleBest)
				{
					male = s;
					maleBest = t;
				}
			}
			else
			{
				if (t > femaleBest)
				{
					female = s;
					femaleBest = t;
				}
			}
		}
		cout << female + " " + male << "\n";
	}
}
