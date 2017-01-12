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
        int high = 50, low = 50, n, cur, ans = 0;
        bool dir = true;    //true for up
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> cur;
            if (low < cur && cur < high)
                continue;
            if (cur > 50){
                if (!dir){
                    dir = true;
                    ans += cur - low;
                }
                else
                    ans += cur - high;
                high = cur;
            }
            else{
                if (dir){
                    dir = false;
                    ans += high - cur;
                }
                else
                    ans += low - cur;
                low = cur;
            }
        }
        cout << ans << "\n";
    }
}
