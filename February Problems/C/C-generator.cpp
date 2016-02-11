#include <bits/stdc++.h>

using namespace std;

int maxval = 1000;

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
	freopen ("C.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{
		int n = random (maxval) + 1;
		cout << n << "\n";
	    vector <int> train (n); 
        for (int i = 0; i < n; i++) 
            train[i] = i+1;
        random_shuffle (train.begin (), train.end ());
        for (int i = 0; i < n; i++){
            cout << train[i];
            if (n - i > 1)
                cout << " ";
        }
        cout << "\n";
    }
}
