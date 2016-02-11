#include <bits/stdc++.h>

using namespace std;

int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
	    int n, c;
        cin >> n;
        set <int> tracks;
        for (int i = 0; i < n; i++){
            cin >> c; 
            if (tracks.lower_bound (n - c) != tracks.end ())
                tracks.erase (tracks.lower_bound (n - c));
            tracks.insert (n - c);
        }
        cout << tracks.size () << "\n";
    }
}
