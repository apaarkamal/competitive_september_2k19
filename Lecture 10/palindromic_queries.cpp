#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		string s;
		cin >> s;
		n = s.size();
		bool dp[n][n];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dp[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		for (i = 0; i < n - 1; i++) {
			dp[i][i + 1] = (s[i] == s[i + 1]);
		}
		for (int r = 0; r < n; r++) {
			for (int l = r - 2; l >= 0; l--) {
				dp[l][r] = (s[l] == s[r] && dp[l + 1][r - 1]);
			}
		}
		cin >> m;
		while (m--) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << (dp[l][r] ? "YES" : "NO") << '\n';
		}
	}
}