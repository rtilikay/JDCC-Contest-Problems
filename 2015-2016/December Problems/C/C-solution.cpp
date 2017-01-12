#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MOD 1000000007

using namespace std;

struct trie{
    char c;
    int val;
    vector <trie*> next;
    trie (char a, int v){
        c = a;
        val = v;
    }
};

void trie_add (trie* cur, string s){
    if (s.length () == 0)
        return;
    for (int i = 0; i < cur->next.size (); i++){
        if (cur->next[i]->c == s[0]){
            cur->next[i]->val ++;
            trie_add (cur->next[i], s.substr (1));
            return;
        }
    }
    cur->next.push_back (new trie (s[0], 1));
    trie_add (cur->next[cur->next.size () - 1], s.substr (1));
}

int count_matches (trie* cur){
    int ans = cur->val;
    ans = (ans*(ans-1))/2;
    if (cur->c != 0 && ans == 0)
        return ans;
    for (int i = 0; i < cur->next.size (); i++)
        ans += count_matches (cur->next[i]);
    return ans;
}

void del_trie (trie* cur){
    for (int i = 0; i < cur->next.size (); i++)
        del_trie (cur->next[i]);
    delete cur;
}

char toUpper (char c){
    if (c < 97)
        return c;
    return c - 32;
}
int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
	    trie* root = new trie (0, 0);
        int n;
        cin >> n;
        string s;
        getline (cin, s);
        for (int i = 0; i < n; i++){
            string rev = "";
            getline(cin, s);
            for (int j = s.length () - 1; j >= 0; j--){
                if (s[j] == ' ')
                    break;
                rev = rev + toUpper (s[j]);
            }
            trie_add (root, rev);
        }
        cout << count_matches (root) << "\n";
        del_trie (root);
	}
}
