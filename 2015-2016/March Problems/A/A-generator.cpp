#include <bits/stdc++.h>

using namespace std;

int maxval = 20;

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
	freopen ("A.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	printf ("%d\n", tt);
	for (int cases = 0; cases < tt; cases++){
	    if (cases == 0)
            cout << "0 0\n0 0\n";
        else if (cases == 1)
            cout << "0 0\n0 1\n";
        else if (cases == 2)
            cout << "0 0\n2 3\n";
        else if (cases == 3)
            cout << "1 0\n0 1\n";
        else if (cases == 4)
            cout << "3 4\n7 8\n";
        else if (cases == 5)
            cout << "3 5\n-6 10\n";
        else if (cases % 2 == 0){
            int x1 = random (21) - 10, y1 = random (21) - 10, x2 = -2*x1, y2 = -2*y1;
            printf ("%d %d\n%d %d\n", x1, y1, x2, y2);
        }
        else
            printf ("%d %d\n%d %d\n", random(21) - 10, random(21) - 10, random(21) - 10, random(21) - 10);
    }
}
