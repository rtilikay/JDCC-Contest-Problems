#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

int random (int mod)
{
    return (rand ()*0x00008000 + rand ())%mod;
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
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{
		int n = random (999)+2;
		cout << n << "\n";
		bool used [100001];
		for (int i = 0; i <= 100000; i++)
			used[i] = false;
		double nums [n];
		for (int i = 0; i < n; i++)
		{
			int temp = random (100001);
			while (used[temp])
				temp = random (100001);
			used[temp] = true;
			nums[i] = temp/1000.0;
		}
		sort (nums, nums+n);
		for (int i = 0; i < n; i++)
			cout << nums[i] << "\n";
	}
}
