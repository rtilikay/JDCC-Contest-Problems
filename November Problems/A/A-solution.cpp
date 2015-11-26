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
		int a, b, n;
		cin >> a >> b >> n;
		cout << a+b*(n-1) << "\n";
	}
}
