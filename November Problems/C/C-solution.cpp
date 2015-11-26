#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 1000000007

using namespace std;

int match (string a, string b){
    int la [26], lb [26], match = 0;
    for (int i = 0; i < 26; i++){
        la[i] = 0;
        lb[i] = 0;
    }
    for (int i = 0; i < a.length (); i++)
        la[a[i]-65]++;
    for (int i = 0; i < b.length (); i++)
        lb[b[i]-65]++;
    for (int i = 0; i < 26; i++)
        match += min (la[i], lb[i]);
    return match;
}

int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        string s;
        int n, best = -1;
        cin >> s >> n;
        string curName, chosen;
        for (int i = 0; i < n; i++){
            cin >> curName;
            int cur = match (s, curName);
            if (cur > best){
                best = cur;
                chosen = curName;
            }
        }
        cout << chosen << "\n";
	}
}
