#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int a[N];

struct segmenttree {
	vector<int> st;
	void init(int n) {
		st.resize(4 * n, INT_MIN);
	}

	void build(int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return ;
		}
		int mid = (start + end) / 2;
		build(start, mid, node * 2 + 1); //left
		build(mid + 1, end, node * 2 + 2); //right
		st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
	}

	void update(int  start, int end, int idx, int val, int node) {
		if (start == end ) {
			a[idx] = val;
			st[node] = a[idx];
			return;
		}
		int mid = (start + end) / 2;
		if (idx <= mid) {
			update(start, mid, idx, val, node * 2 + 1);
		}
		else {
			update(mid + 1, end , idx, val, node * 2 + 2);
		}
		st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
	}

	int query(int start, int end, int l, int r, int node) {
		if (start > r || end < l || start > end) return INT_MIN;
		if (start >= l && end <= r) return st[node];
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, node * 2 + 1);//query left
		int q2 = query(mid + 1, end, l, r, node * 2 + 2);//query right
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
		}
		tree.init(n);
		tree.build(0, n - 1, 0);
		cout << tree.query(0, n - 1, 2, 5, 0) << '\n';
		tree.update(0, n - 1, 4, 90, 0);
		cout << tree.query(0, n - 1, 2, 5, 0) << '\n';
	}
}