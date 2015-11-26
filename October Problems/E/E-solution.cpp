#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 1000000007

using namespace std;

struct point {
	int x, y, h;
	point (){}
	point (int a, int b, int c){
		x = a;
		y = b;
		h = c;
	}
};

struct comp {
	bool operator () (const point& a, const point& b){
		return a.h > b.h;
	}
};

int main ()
{
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
		int r, c;
		cin >> r >> c;
		int** mat = new int* [r];
		bool**vis = new bool* [r];
		for (int i = 0; i < r; i++)
		{
			mat[i] = new int [c];
			vis[i] = new bool [c];
			for (int j = 0; j < c; j++)
			{
				cin >> mat[i][j];
				vis[i][j] = false;
			}
		}
		priority_queue <point, vector<point>, comp> pq;
		pq.push (point (0, 0, mat[0][0]));
		vis[0][0] = true;
		int waterlevel = mat[0][0], locations = 0;
		int volume = 0;
		bool done = false;
		while (!pq.empty ())
		{
			point next = pq.top ();
			int x = next.x, y = next.y;
			pq.pop ();
			if (done && next.h >= waterlevel)
				continue;
			if (next.h >= waterlevel)
			{
				volume = (volume + (((long long)locations)*((long long)(next.h-waterlevel+1))%MOD) + 1)%MOD;
				waterlevel = next.h+1;
			}
			else
			{
				volume = (volume + waterlevel-next.h)%MOD;
			}
			locations ++;
			if (x == r-1 && y == c-1)
			{
				done = true;
				continue;
			}
			if (x > 0 && !vis[x-1][y])
			{
				pq.push (point (x-1,y,mat[x-1][y]));
				vis[x-1][y] = true;
			}
			if (x < r-1 && !vis[x+1][y])
			{
				pq.push (point (x+1,y,mat[x+1][y]));
				vis[x+1][y] = true;
			}
			if (y > 0 && !vis[x][y-1])
			{
				pq.push (point (x,y-1,mat[x][y-1]));
				vis[x][y-1] = true;
			}
			if (y < c-1 && !vis[x][y+1])
			{
				pq.push (point (x,y+1,mat[x][y+1]));
				vis[x][y+1] = true;
			}
		}
		cout << volume << "\n";
	}
}
