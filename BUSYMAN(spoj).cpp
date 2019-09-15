#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

bool comp(P a, P b) {
	return a.S < b.S;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		vector<P> v(n);
		for (i = 0; i < n; i++) {
			cin >> v[i].F >> v[i].S;
		}
		sort(v.begin(), v.end(), comp);
		int last = v[0].S;
		ans = 1;
		for (i = 1; i < n; i++) {
			if (last <= v[i].F) {
				last = v[i].S;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}