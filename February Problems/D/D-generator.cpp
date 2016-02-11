#include <bits/stdc++.h>

using namespace std;

int maxval = 25000, lowermaxval = 1000;

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
        int n = random (maxval-1) + 2;
        if (cases < tt/2)
            n = random (lowermaxval - 1) + 2;
        if (cases == tt/2){
            n = 200000;
            cout << n << "\n";
            for (int i = 2; i <= n; i++)
                cout << "1 " << i << "\n";
            continue;
        }
        cout << n << "\n";
        for (int i = 2; i <= n; i++)
            cout << random (i-1) + 1 << " " << i << "\n";
    }
}
