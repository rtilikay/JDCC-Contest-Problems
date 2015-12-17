#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 1000000007

using namespace std;

int main ()
{
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int n;
		cin >> n;
		for (int i = n; i >= 1; i--)
            cout << i << " ";
        cout << "0!\n";
	}
}
