#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int maxval = 100, probTree = 50;

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
	freopen ("D.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
    cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++){
        int n = random (maxval - 9) + 10;
        cout << n << "\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (random (100) <= probTree)
                    cout << "X";
                else
                    cout << "O";
            }
            cout << "\n";
        }
	}
}
