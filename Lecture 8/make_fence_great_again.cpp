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

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n], b[n];
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		int dp[n][3];
		for (i = 0; i < n; i++) {
			dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
		}
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];
		for (i = 1; i < n; i++) {
			for (j = 0; j < 3; j++) { //i wale ko j se
				for (k = 0; k < 3; k++) { // i-1 wale ko k se
					if (a[i] + j != a[i - 1] + k) {
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
					}
				}
			}
		}
		cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
	}
}