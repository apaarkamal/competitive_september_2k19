#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 300005;
vector<int> st[N];
int a[N];

void build(int l, int r, int node) {
	if (l == r) {
		st[node].pb(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, node * 2 + 1);
	build(mid + 1, r, node * 2 + 2);
	merge(st[node * 2 + 1].begin(), st[node * 2 + 1].end(), st[node * 2 + 2].begin(), st[node * 2 + 2].end(), back_inserter(st[node]));
}

int getans(int si, int se, int l, int r, int node, int k) {
	if (se < l || si > r) {
		return 0;
	}
	if (si >= l && se <= r) {
		return st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
	}
	int mid = (si + se) / 2;
	int q1 = getans(si, mid, l, r, node * 2 + 1, k);
	int q2 = getans(mid + 1, se, l, r, node * 2 + 2, k);
	return q1 + q2;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		build(0, n - 1, 0);
		cin >> m;
		while (m--) {
			int l, r;
			cin >> l >> r >> k;
			l ^= ans; r ^= ans; k ^= ans;
			l--; r--;
			ans = getans(0, n - 1, l, r, 0, k);
			cout << ans << '\n';
		}
	}
}