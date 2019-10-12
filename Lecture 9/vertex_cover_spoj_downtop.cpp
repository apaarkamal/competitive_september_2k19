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

int dp[N][2];
vector<int> gr[N];

void dfs(int cur, int par) {
	dp[cur][1] = 1;
	dp[cur][0] = 0;
	for (auto x : gr[cur]) {
		if (x != par) {
			dfs(x, cur);
			// x is visited
			dp[cur][1] += min(dp[x][0], dp[x][1]);
			dp[cur][0] += dp[x][1];
		}
	}
	db(cur, dp[cur][0], dp[cur][1]);
}

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
		dfs(1, 0);
		cout << min(dp[1][0], dp[1][1]);
	}
}