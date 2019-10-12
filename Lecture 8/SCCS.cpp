#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;
int vis[N], col[N], cnt;
vector<int> order, component;
vector<int> g[N], gr[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : g[cur]) {
		if (!vis[x]) dfs(x);
	}
	order.pb(cur);
}

void dfs1(int cur) {
	vis[cur] = 1;
	component.pb(cur);
	col[cur] = cnt;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs1(x);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y);
			gr[y].pb(x);
		}
		for (i = 1; i <= n; i++) {
			if (!vis[i]) dfs(i);
		}
		reverse(order.begin(), order.end());
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < order.size(); i++) {
			if (!vis[order[i]]) {
				component.clear();
				cnt++;
				dfs1(order[i]);
				////in component vector scc will be stored
			}
		}
	}
}