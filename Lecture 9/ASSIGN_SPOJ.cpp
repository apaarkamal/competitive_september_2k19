#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 21;

int a[N][N], res, n, memo[N][1 << N];

int solve(int row, int mask) {
	if (row == n) {
		return 1;
	}
	if (memo[row][mask] != -1) return memo[row][mask];
	int ans = 0;
	for (int col = 0; col < n; col++) {
		if (a[row][col] && !((mask >> col) & 1)) {
			ans += solve(row + 1, mask ^ (1 << col));
		}
	}
	return memo[row][mask] = ans;
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
			for (j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		memset(memo, -1, sizeof(memo));
		cout << solve(0, 0) << '\n';
	}
}