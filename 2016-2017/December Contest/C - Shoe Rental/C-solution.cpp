#include <bits/stdc++.h>

using namespace std; 

int main () {
    int n, k;
    cin >> n >> k;
    int alley [k];
    vector<int> wanted(k, 0);
    for (int i = 0; i < k; i++)
        cin >> alley[i];
    for (int i = 0; i < n; i++) {
        int temp; 
        cin >> temp;
        wanted[--temp]++;
    }
    int served = 0;
    for (int i = 0; i < k; i++) {
        while (alley[i]) {
            if (i > 0 && wanted[i-1]) {
                served++;
                wanted[i-1]--;
                alley[i]--;
            } else if (wanted[i]) {
                served++;
                wanted[i]--;
                alley[i]--;
            } else if (i < k-1 && wanted[i+1]) {
                served++;
                wanted[i+1]--;
                alley[i]--;
            } else
                break;
        }
    }
    cout << served << "\n";
}

