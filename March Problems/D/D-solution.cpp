#include <bits/stdc++.h>

using namespace std;

const int MOD = 40009;
const int MAX = 16383;

int inv [MOD];

int inverse (int n){
    int r1 = MOD, r2 = n, s1 = 0, s2 = 1, q, temp;
    for (int i = 0; r2 != 1; i++){
        q = r1/r2;
        temp = r2;
        r2 = r1 - q*r2;
        r1 = temp;
        temp = s2;
        s2 = s1 - q*s2;
        s1 = temp;
    }
    return (s2 + MOD)%MOD;
}

void gen_inverses (){
    for (int i = 1; i < MOD; i++)
        inv [i] = inverse (i);
}

int next (int n){
    return (1997*n)%MOD;
}

int main ()
{
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
    gen_inverses ();
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++){
        int n; 
        cin >> n; 
        int enc [n];
        for (int i = 0; i < n; i++)
            cin >> enc[i];
        char original [2*n];
        for (int i = 1; i < MOD; i++){
            int cur = i;
            bool bad = false;
            for (int j = 0; j < n; j++){
                if ((enc[j]*inv[cur]) % MOD >= MAX){
                    bad = true;
                    break;
                }
                int val = (enc[j]*inv[cur]) % MOD;
                original[2*j] = val/128;
                original[2*j+1] = val%128;
                cur = next (cur);
            }
            if (!bad){
                for (int i = 0; i < 2*n; i++)
                    cout << original[i];
                cout << "\n";
                break;
            }
        }
    }
}
