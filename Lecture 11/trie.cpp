// Author : Apaar
// Built  : 19-10-2019 14:18:53

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct node {
	bool is_end;
	node *nxt[26];
	node() {
		is_end = false;
		for (int i = 0; i < 26; i++) {
			nxt[i] = NULL;
		}
	}
};

node* root;

void insert(string s) {
	node *cur = root;
	for (int i = 0; i < (int)(s.size()); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			cur->nxt[s[i] - 'a'] = new node();
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	cur->is_end = 1;
}

bool present(string s) {
	node *cur = root;
	for (int i = 0; i < (int)(s.size()); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			return false;
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	return cur->is_end;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		root = new node();
		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			insert(s);
		}
		cin >> m;
		while (m--) {
			string s;
			cin >> s;
			if (present(s)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}