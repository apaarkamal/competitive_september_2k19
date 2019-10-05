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
vector<int> order;
int vis[N];
bool cycle = false;

void dfs(int cur) {
	vis[cur] = 1;//cur dfs
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x);
		else if (vis[x] == 1) cycle = true;
	}
	// we are at this position when whole
	// subtree of cur is visited
	order.pb(cur);
	vis[cur] = 2; // leave dfs
}


int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m ;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
		}
		for (i = 0; i < N; i++) {
			sort(gr[i].begin(), gr[i].end());
			reverse(gr[i].begin(), gr[i].end());
		}
		for (i = n; i >= 1; i--) {
			if (!vis[i]) dfs(i);
		}
		if (cycle) {
			cout << "Sandro fails.";
			return 0;
		}
		reverse(order.begin(), order.end());
		for (auto x : order) {
			cout << x << " ";
		}
	}
}