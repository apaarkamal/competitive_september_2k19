#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int pr[N];
vector<int> primes;

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			primes.pb(i);
			for (j = i; j < N; j += i) {
				pr[j]++;
			}
		}
	}
}


int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	seive();
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int l, r;
		cin >> l >> r;
		int a[r - l + 1];
		for (i = 0; i < r - l + 1; i++) {
			a[i] = i + l;
		}
		for (auto x : primes) {
			if (x * x > r) break;
			int start = (l / x) * x;
			if (x >= l) start = x * 2;
			for (i = start ; i <= r ; i += x) {
				if (i < l) continue;
				//////////////////////
				while (a[i - l] % x == 0 ) {
					a[i - l] /= x;
				}
			}
		}
		for (i = 0; i < r - l + 1; i++) {
			if (a[i] == i + l && i + l != 1)  {
				cout << i + l << "\n";
			}
		}
		cout << '\n';
	}
}