#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

#define sizeNames 2708

using namespace std;

int maxval = 100, minval = 50;

int random (int mod)
{
	return abs(rand () * 0x0008000 + rand ()) % mod;
}

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Incorrect number of arguments!\n";
		return 1;
	}
	freopen ("C.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{
		int n = random (maxval-minval+1) + minval, l = random (maxval/2) + 1;
		cout << n << "\n";
		char valid [4] = {'A', 'a', 'B', 'b'};
		for (int i = 0; i < n; i++){
            for (int j = 0; j < l; j++)
                cout << valid [random (4)];
            cout << " ";
            for (int j = 0; j < l; j++)
                cout << valid[random(4)];
            cout << "\n";
		}
	}
}
