#include <bits/stdc++.h>

using namespace std;

vector <int> adj [200001];
int n;

pair <int, int> find (int start){
    queue <pair<int, int> > q;
    vector <bool> vis (n+1, 0);
    vis[start] = 1;
    q.push (pair <int, int> (start, 0));
    pair <int, int> cur;
    while (!q.empty ()){
        cur = q.front (); 
        q.pop ();
        for (int i = 0; i < adj[cur.first].size (); i++)
            if (!vis[adj[cur.first][i]]){
                vis[adj[cur.first][i]] = true;
                q.push (pair <int, int> (adj[cur.first][i], cur.second + 1));
            }
    }
    return cur;
}
int main (){
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
    cin.sync_with_stdio (0); 
    cin.tie (0);
    int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        if (cases > 0)
            for (int i = 0; i <= n; i++)
                adj[i].clear ();
        cin >> n;
        for (int i = 0; i < n-1; i++){
            int a, b; 
            cin >> a >> b; 
            adj[a].push_back (b); 
            adj[b].push_back (a);
        }
        cout << find(find(1).first).second+1<< "\n";
    }
}
