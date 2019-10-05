#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<P> gr[N];
vector<vector<int>> edges;

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
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			gr[x].pb({y, w});
			gr[y].pb({x, w});
			edges.pb({w, x, y});
		}
		G.init(n + 10);
		sort(edges.begin(), edges.end());
		for (i = 0; i < m; i++) {
			int w = edges[i][0], x = edges[i][1], y = edges[i][2];
			if (G.get(x) != G.get(y)) {
				ans += w;
				G.unite(x, y);
			}
		}
		cout << ans;
	}
}