#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

int maxval = 1000;

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
	freopen ("A.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{
		int a = random (maxval)+1, b = random (maxval)+1, c = random (maxval)+1;
		while (c == b)
            c = random (maxval)+1;
		cout << b << "\n" << abs (b-a) << "\n" << c << "\n" << abs (c-a) << "\n";
	}
}
