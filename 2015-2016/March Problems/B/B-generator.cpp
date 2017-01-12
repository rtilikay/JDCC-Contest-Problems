#include <bits/stdc++.h>

using namespace std;

int maxval = 100;

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
    vector <int> nums (maxval + 1);
	for (int cases = 0; cases < tt; cases++){
	    int n = random (maxval - 1) + 1;
        vector <int> permutation (99);
        for (int i = 0; i < 99; i++)
            permutation[i] = (i == 49)?100:(i+1);
        random_shuffle (permutation.begin (), permutation.end ());
        cout << n << "\n";
        for (int i = 0; i < n; i++){
            cout << permutation[i];
            if (i != n-1)
                cout << " ";
        }
        cout << "\n";
    }
}
