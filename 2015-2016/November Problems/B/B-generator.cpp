#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int maxval = 100;

int random (int mod){
        return abs(rand ()*0x00008000 + rand ())%mod;
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
        int h = random (maxval), w = random(maxval);
        printf ("%d %d\n", h+1, w+1);
	}
}
