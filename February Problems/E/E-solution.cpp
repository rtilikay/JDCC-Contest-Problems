#include <bits/stdc++.h>

using namespace std;

int main ()
{
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--)
	{
	    int n, m, k; 
        cin >> n >> m >> k;
        int grocer [n], rosie [m], sum = 0;
        for (int i = 0; i < n; i++)
            cin >> grocer[i];
        for (int i = 0; i < m; i++){
            cin >> rosie[i];
            sum+= rosie[i];
        }
        //Grocer (Coin) DP
        vector <int> gdp (sum+1, 0x30707070);
        gdp[0] = 0;
        for (int i = 1; i <= sum; i++)
            for (int j = 0; j < n; j++)
                if (i >= grocer[j])
                    gdp[i] = min (gdp[i], 1 + gdp[i-grocer[j]]);
        
        //Rosie (Knapsack) DP
        vector <int> rdp (sum+1, 0x80808080);
        rdp[0] = 0;
        for (int j = 0; j < m; j++)
            for (int i = sum; i >= 0; i--)
                if (i >= rosie[j])
                    rdp[i] = max (rdp[i], 1 + rdp[i - rosie[j]]);

        //Finding the best value.
        int best = 0x70707070;
        for (int i = k; i <= sum; i++){
            if (rdp [i] >= 0 && gdp[i-k] <= sum)
                best = min (best, m - rdp[i] + gdp[i-k]);
        }
        cout << best << "\n";
    }
}
