#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 1000000007

using namespace std;

int main ()
{
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int n, m;
		cin >> n >> m;
		if (n % (m+1) == 0)
            cout << "Matthew" << "\n";
        else
            cout << "Emily" << "\n";
	}
}
