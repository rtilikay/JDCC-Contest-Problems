#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

int maxInput = 1200;

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
	for (int cases = 0; cases < tt; cases++)
	{
		int n = rand()%maxInput+1;
		int d = rand()%(maxInput-n)+n;
		cout << n << " " << d << "\n";
	}
}
