#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int minval = 10, maxval = 50;

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
	freopen ("D.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
    cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++){
        int n = 2*(random (maxval-minval)+minval);
        string s = "";
        for (int i = 0; i < n; i++){
            if (i >= n/2 && cases % 20 == 5)
                s = s + '9';
            else if (i >= n/2 && cases % 20 == 15){
                if (i == n-1)
                    s = s + '8';
                else
                    s = s + '9';
            }
            else
                s = s + (char)(random (10) + 48);
        }
        cout << s << "\n";
	}
}
