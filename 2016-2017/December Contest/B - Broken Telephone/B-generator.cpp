#include <bits/stdc++.h>

using namespace std; 

const int BOUND = 100;
const int BOUND_CASES = 10;

int main () {
    srand(time(0));
    int cases = BOUND_CASES;
    cout << cases << "\n";
    while (cases--) {
        int n = rand()%BOUND+1;
        cout << n << "\n";
        string cur = "reyno";
        while (n--) {
            cout << cur << "\n";
            int casework = rand()%(10*BOUND);
            if (casework < 10) {
                if (casework < 4)
                    cur = to_string(rand()%10000);
                else if (casework < 7 && cur.length() > 2)
                    cur = cur.substr(0, cur.length() - 1);
                else
                    cur = cur + "b";
            } else {
                int ind = rand()%cur.length();
                if (cur[ind] < 97 || cur[ind] > 121)
                    cur[ind] = 'a';
                else
                    cur[ind] = (char)(cur[ind] + 1);
            }
        }
    }
}
