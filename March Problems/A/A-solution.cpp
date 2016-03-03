#include <bits/stdc++.h>

using namespace std;

int main ()
{
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (abs (x2) < abs(x1)){
            swap (x1, x2);
            swap (y1, y2);
        }
        if (x1*y2 != x2*y1 || (x1 != 0 && x2%x1 != 0) || (y1 != 0 && y2 % y1 != 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
