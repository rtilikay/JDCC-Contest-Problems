#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int maxrow = 150, maxheight = 1000000;

int random (int mod)
{
	return (rand () * 0x0008000 + rand ()) % mod;
}

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Incorrect number of arguments!\n";
		return 1;
	}
	freopen ("E.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{

		int r = random (maxrow)+1, c = random (maxrow)+1;
		if (cases == 0)
		{
			r = maxrow; c = maxrow;
			cout << r << " " << c << "\n";
			for (int i = 0; i < r; i++)
			{
				int cur = i%4;
				if (cur == 0 || cur == 2)
					for (int j = 0; j < c; j++)
						cout << "1 ";
				else if (cur == 1)
				{
					for (int j = 0; j < c-1; j++)
						cout << maxheight-1 << " ";
					if (i == r-1)
						cout << maxheight/2-1;
					else
						cout << "1";
				}
				else if (cur == 3)
				{
					cout << "1";
					for (int j = 1; j < c; j++)
						cout << " " << maxheight-1;
				}
				cout << "\n";
			}
			continue;
		}
		if (cases == 1)
		{
			r = maxrow; c = maxrow;
			cout << r << " " << c << "\n";
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c-1; j++)
					cout << "1 ";
                cout << maxheight/2 << "\n";
			}
			continue;
		}
		cout << r << " " << c << "\n";
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cout << random (maxheight)+1 << " ";
			cout << "\n";
		}
	}
}
