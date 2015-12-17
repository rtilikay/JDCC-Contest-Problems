#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int maxn = 10000000, maxm = 10000, maxb = 1000;

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
	freopen ("E.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
    cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++){
        int n = random (maxn-1) + 2, m = random(maxm) + 1;
        if (cases == 0){
            n = maxn;
            m = maxm;
            cout << n << " " << m << "\n";
            for (int i = 0; i < m; i++)
                cout << "1 " << random (10) + (maxn - 11) << " " << random (maxb) + 1 << "\n";
            continue;
        }
        cout << n << " " << m << "\n";
        for (int i = 0; i < m; i++){
            int a = random (n-1) + 1, b = random (maxb) + 1, l = random (n-a) + 1;
            cout << a << " " << l << " " << b << "\n";
        }
	}
}
