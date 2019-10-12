#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 200005;

vector<int> gr[N];
int a[N];
map<int, int> mp[N];

int pr[N], res;
vector<int> prime_divisors[N];

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			for (j = i; j < N; j += i) {
				pr[j]++;
				prime_divisors[j].pb(i);
			}
		}
	}
}

void dfs(int cur, int par, int dep) {
	for (auto x : prime_divisors[a[cur]]) {
		mp[cur][x] = dep;
	}
	for (auto child : gr[cur]) {
		if (child != par) {
			dfs(child, cur, dep + 1);
			for (auto x : mp[child]) {
				if (a[cur] % x.F == 0) {
					res = max(res, x.S + mp[cur][x.F] - 2 * dep + 1);
				}
			}
			for (auto x : mp[child]) {
				if (a[cur] % x.F == 0) {
					mp[cur][x.F] = max(mp[cur][x.F], x.S);
				}
			}
		}
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] > 1) res = 1;
		}
		for (i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		dfs(1, 0, 0);
		cout << res;
	}
}