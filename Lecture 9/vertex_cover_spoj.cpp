#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int memo[N][2];
vector<int> gr[N];

int dfs(int cur, int taken, int par) {
	if (memo[cur][taken] != -1) return memo[cur][taken];
	int ans = 0;
	for (auto x : gr[cur]) {
		if (x != par) {
			if (taken) ans += min(dfs(x, 1, cur), dfs(x, 0, cur));
			else ans += dfs(x, 1, cur);
		}
	}
	if (taken) ans++;
	return memo[cur][taken] = ans;
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		memset(memo, -1, sizeof(memo));
		cout << min(dfs(1, 0, 0), dfs(1, 1, 0));
	}
}