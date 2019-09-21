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

int a[N], b[N];

struct segmenttree {
	vector<int> st;
	void init(int _n) {
		st.clear();
		st.resize(4 * _n, INT_MIN);
	}
	void build(int l, int r, int node) {
		if (l == r) {
			st[node] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, node * 2 + 1);
		build(mid + 1, r, node * 2 + 2);
		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	}

	void update(int l, int r, int indup, int val, int node) {
		if (l == r) {
			if (st[node] == INT_MIN) {
				st[node] = val;
			}
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = max(st[2 * node + 1], st[2 * node + 2]);
		}
	}

	int query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return INT_MIN;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		int q1 = query(si, mid, l, r, node * 2 + 1);
		int q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return max(q1, q2);
	}
} tree;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		for (i = 0; i < n; i++) {
			a[i] = lower_bound(b, b + n, a[i]) - b + 1;
		}
		tree.init(n);
		vector<int> v;
		for (i = n - 1; i >= 0; i--) {
			int val = tree.query(0, n - 1, 0, a[i] - 1, 0);
			if (val == INT_MIN) {
				v.pb(-1);
			}
			else {
				v.pb(val - i - 1);
			}
			tree.update(0, n - 1, a[i], i, 0);
		}
		reverse(v.begin(), v.end());
		for (auto x : v) {
			cout << x << " ";
		}
	}
}