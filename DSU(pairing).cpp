#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005;

struct dsu {
	vector<int> par, sz;

	void init(int n) {
		par.resize(n); sz.resize(n, 1);
		for (int i = 0; i < n; i++) par[i] = i;
	}

	int get_par(int x) {
		if (par[x] == x) return x;
		else return par[x] = get_par(par[x]);
	}

	void unite(int x, int y) {
		x = get_par(x);
		y = get_par(y);
		if (x != y) {
			par[y] = x;
			sz[x] += sz[y];
			sz[y] = 0;
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
		G.init(n);
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			G.unite(x, y);
		}
		for (i = 0; i < n; i++) {
			ans += n - G.sz[G.get_par(i)];
		}
		cout << ans / 2;
	}
}