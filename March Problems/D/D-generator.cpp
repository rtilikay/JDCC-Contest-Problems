#include <bits/stdc++.h>

using namespace std;

const int maxval = 1000;
const int MOD = 40009;

int random (int mod)
{
	return abs(rand () * 0x0008000 + rand ()) % mod;
}

int next (int n){
    return (1997*n)%MOD;
}

char small (){
    int r = random (27);
    if (!r)
        return 32;
    return 64 + r;
}

char large (){
    return random (95) + 32;
}

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Incorrect number of arguments!\n";
		return 1;
	}
	freopen ("D.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
	cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++)
	{
		int n = random (maxval-99) + 100, cur = random (MOD-1) + 1;
        if (cases < tt/2)
            cur = random (1000) + 1;
        cout << n << "\n";
        char message [2*n];
        for (int i = 0; i < n; i++){
            if (cases < tt/2){
                message[2*i] = small ();
                message[2*i + 1] = small ();
            }
            else{
                message[2*i] = large ();
                message[2*i + 1] = large ();
            }
            int pair = ((int)message[2*i])*128 + ((int)message[2*i+1]);
            cout << (pair*cur)%MOD;
            if (i != n-1)
                cout << " ";
            cur = next (cur);
        }
        cout << "\n";
    }
}
