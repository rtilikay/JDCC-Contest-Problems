#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int maxval = 1000, maxm = 100;

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
	freopen ("B.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	printf ("%d\n", tt);
	for (int cases = 0; cases < tt; cases++){
        int n = random (maxval) + 1, m = random(maxm) + 1;
        if (random (100) < 49)
            n = (random (10)+1)*(m+1);
        cout << n << " " << m << "\n";
	}
}
