#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 1000000007
#define maxval 1000000

using namespace std;

int dA [20001], coords [20001], it;

int binsearch (int arr [], int left, int right, int key){
    if (left > right)
        return -1;
    int mid = (left + right)/2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binsearch (arr, left, mid - 1, key);
    return binsearch (arr, mid + 1, right, key);
}

int main ()
{
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--)
	{
	    int n, m;
	    cin >> n >> m;
	    int s [m], f[m], b[m];
        for (int i = 0; i <= 2*m; i++)
            dA[i] = 0;
        for (int i = 0; i < m; i++){
            scanf ("%d %d %d", s+i, f+i, b+i);
            f[i] += s[i];
            coords[2*i] = s[i];
            coords[2*i + 1] = f[i];
        }
        sort (coords, coords + 2*m);
        it = 1;
        for (int i = 1; i < 2*m; i++)
            if (coords[i] != coords[i-1])
                coords[it++] = coords[i];
        for (int i = 0; i < m; i++){
            int a = binsearch (coords, 0, it, s[i]);
            int c = binsearch (coords, 0, it, f[i]);
            dA[a] += b[i];
            dA[c] -= b[i];
        }
        int best = 0;
        for (int i = 1; i < it; i++){
            dA[i] += dA[i-1];
            if (dA[i] >= dA[best])
                best = i;
        }
        cout << coords[best+1]-1 << "\n";
	}
}
