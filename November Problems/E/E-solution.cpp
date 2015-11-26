#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 1000000007
#define maxval 1000000

using namespace std;

int len [maxval], path [maxval];

int main ()
{
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        //cout << cases << "\n";
        long long a, b, p;
        cin >> a >> b >> p;
        for (int i = 0; i < p; i++)
            len[i] = 0;
        //int cycles = 0;
        for (int seed = 0; seed < p; seed++){
            if (len[seed] != 0)
                continue;
            //cycles++;
            int it = 0;
            path[it++] = seed;
            len[seed] = -1;
            int cur = seed;
            for (int i = 1;;i++){
                int next = (a*cur + b)%p;
                if (len[next] == 0){
                    len[next] = -1;
                    cur = next;
                    path[it++] = next;
                    continue;
                }
                if (len[next] > 0){
                    for (int j = it - 1; j >= 0; j--)
                        len[path[j]] = len[next] + it - j;
                    break;
                }
                if (len[next] == -1){
                    if (next == seed){
                        for (int j = 0; j < it; j++)
                            len[path[j]] = i;
                    }
                    else{
                        int cut = 0;
                        for (int j = 0; j < it; j++){
                            if (path[j] == next){
                                cut = j;
                                break;
                            }
                        }
                        for (int j = 0; j < it; j++){
                            if (j < cut)
                                len[path[j]] = i - j;
                            else
                                len[path[j]] = i - cut;
                        }
                    }
                    break;
                }
            }
        }
        //cout << "cycles: " << cycles << endl;
        double avg = 0;
        for (int i = 0; i < p; i++)
            avg += len[i];
        printf ("%.6f\n",avg/p);
	}
}
