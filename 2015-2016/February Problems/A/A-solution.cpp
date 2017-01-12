#include <bits/stdc++.h>

using namespace std;

string reverse (string s){
    string r = "";
    for (int i = 0; i < s.size (); i++)
        r = s[i] + r;
    return r;
}

int main ()
{
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
	    string s;
        cin >> s; 
        if (s == reverse (s))
            cout << "YAY\n";
        else
            cout << "NAY\n";
    }
}
