#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> give_prime_factors(int n) {
	V<int> v;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			v.pb(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		v.pb(n);
	}
	return v;
}
int dp[N];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			vector<int> v = give_prime_factors(a[i]);
			int mx = 0;
			for (auto x : v) {
				mx = max(mx, dp[x]);
			}
			for (auto x : v) {
				dp[x] = mx + 1;
			}
		}
		for (i = 0; i < N; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans;
	}
}