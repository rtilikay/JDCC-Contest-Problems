#include <bits/stdc++.h>

using namespace std;

const long long maxn = 6, maxm = 1000000000000000, smallm = 50;

long long random (long long mod)
{
    long long first = rand (), second = rand (), third = rand ();
    second = second * 0x00010000 + third;
    first = second * 0x00010000 + first;
    return abs (first) % mod;
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
        long long n = random (4) + 3, m;
        if (cases <= 0.3*tt)
            m = random (40/n) + 1;
        else if (cases <= 0.7*tt)
            m = random (smallm - 11) + 12;
        else
            m = random (maxm);
        if (n % 2 && m % 2 && m != 1)
            m--;
        cout << n << " " << m << "\n";
    }
}
