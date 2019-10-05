#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> gr[N];
int vis[N];

void dfs(int cur, int cnt) {
	vis[cur] = cnt;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x, cnt);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		cnt = 0;
		for (i = 1; i <= n; i++) {
			if (!vis[i]) {
				cnt++;
				dfs(i, cnt);
			}
		}
		// for (i = 1; i <= n; i++) {
		// 	cout << vis[i] << " ";
		// }
		cout << cnt;
	}
}