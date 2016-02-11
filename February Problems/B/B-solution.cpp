#include <bits/stdc++.h>
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
	    int n, l, ans = 0;
        cin >> n >> l;
        for (int i = 0; i < n; i++){
            int p; 
            string dir; 
            cin >> p >> dir;
            if (dir == "left")
                ans = max (ans, p);
            else
                ans = max (ans, l - p);
        }
        cout << ans << "\n";
    }
}
