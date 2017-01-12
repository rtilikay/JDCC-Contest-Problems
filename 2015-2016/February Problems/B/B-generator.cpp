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
        int l = random(maxval) + 1, n = random (l+1) + 1;
        cout << n << " " << l << "\n";
        for (int i = 0; i <= l; i++)
            nums[i] = i;
        random_shuffle (nums.begin (), nums.begin () + l);
        for (int i = 0; i < n; i++){
            string dir = (random(2))?"left":"right";
            cout << nums[i] << " " << dir << "\n";
        }
	}
}
