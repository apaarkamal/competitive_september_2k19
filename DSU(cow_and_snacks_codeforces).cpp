#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct dsu {
	vector<int> p, sz;
	void init(int NN) {
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN, 1);
		iota(p.begin(), p.end(), 0);
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
		}
	}
} G;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> k >> n;
		G.init(N);
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			G.unite(x, y);
		}
		for (i = 0; i < N; i++) {
			if (G.sz[i] > 0) {
				ans += (G.sz[i] - 1);
			}
		}
		cout << n - ans;
	}
}