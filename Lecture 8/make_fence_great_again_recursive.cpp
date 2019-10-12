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

const int N = 300005;

int dp[N][3], n;
int a[N], b[N];

int fun(int cur, int prev, int num) {
	if (cur == n) return 0;
	int &ans = dp[cur][num];
	if (ans != -1) return ans;
	ans = 1e18;
	if (a[cur] != prev) ans = min(ans, fun(cur + 1, a[cur], 0));
	if (a[cur] + 1 != prev) ans = min(ans, b[cur] + fun(cur + 1, a[cur] + 1, 1));
	if (a[cur] + 2 != prev) ans = min(ans, 2 * b[cur] + fun(cur + 1, a[cur] + 2, 2));
	return ans;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		for (i = 0; i <= n; i++) {
			dp[i][0] = dp[i][2] = dp[i][1] = -1;
		}
		cout << fun(0, -1, 0) << '\n';
	}
}