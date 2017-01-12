#include <bits/stdc++.h>

using namespace std;

int maxval = 100, maxk = 1000,  maxsum= 10000;

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
	    int n = random (maxval) + 1, m = random (maxval-1) + 2, k = random (maxk) + 1;
        if (cases < tt/2)
            m = 1;
        cout << n << " " << m << " " << k << "\n";
        cout << "1";
        vector <int> grocer (10*n-1);
        for (int i = 0; i < 10*n-1; i++)
            grocer[i] = i+2;
        random_shuffle (grocer.begin (), grocer.end ());
        for (int i = 1; i < n; i++)
            cout << " " << grocer[i];
        cout << "\n";
        for (int i = 0; i < m; i++){
            cout << random ((maxsum - k)/m) + k/m + 1; //Keeps sum of all coins in the range (k, maxsum].
            if (m - i > 1)
                cout << " ";
        }
        cout << "\n";
    }
}
