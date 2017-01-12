#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int lowerval = 1000, maxval = 1000000;

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
	freopen ("E.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
    cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++){
        int a, b, p;
        if (cases < 20){
            a = random (lowerval) + 1;
            b = random (lowerval) + 1;
            p = random (lowerval - 1) + 2;
        }
        else{
            a = random (lowerval) + 1;
            b = random (maxval) + 1;
            p = random (maxval - 1) + 2;
        }
        if (cases == 20){
            a = 1;
            b = 1;
            p = maxval;
        }
        cout << a << " " << b << " " << p << "\n";
	}
}
