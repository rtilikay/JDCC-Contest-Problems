#include <bits/stdc++.h>

using namespace std;

int maxval = 20;

int random (int mod)
{
	return abs(rand () * 0x0008000 + rand ()) % mod;
}

string genstring (int n){
    string s = "";
    for (int i = 0; i < n; i++)
        s = s + (char)(random (26) + 65);
    return s;
}

string reverse (string s){
    string r = "";
    for (int i = 0; i < s.size (); i++)
        r = s[i] + r;
    return r;
}

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Incorrect number of arguments!\n";
		return 1;
	}
	freopen ("A.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	printf ("%d\n", tt);
	for (int cases = 0; cases < tt; cases++){
        if (cases == 72){
            cout << "A\n";
            continue;
        }
        int n = random (maxval) + 1;
        if (random (3)){
            string s = genstring (n);
            if (random (2))
                s = s + (char)(random (26) + 65) + reverse(s);
            else
                s = s + reverse (s);
            cout << s << "\n";
        }
        else
            cout << genstring (n) << "\n";
	}
}
