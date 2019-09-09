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

const int N = 100005, mod = 1e9;
const int sz = 10;

struct Mat {
	int m[sz][sz];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	void identity() {
		for (int i = 0; i < sz; i++) {
			m[i][i] = 1;
		}
	}
	Mat operator* (const Mat &a) const
	{
		Mat r;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					r.m[i][j] = (r.m[i][j] + m[i][k] * a.m[k][j]) % mod;
		return r;
	}
};

int solve(int b[], int c[], int k, int n) {
	if (n <= k) {
		return b[n - 1];
	}
	else {
		int e = n - k ;
		Mat res, a;
		res.identity();
		for (int i = 0; i < k; i++) {
			a.m[0][i] = c[i];
		}
		for (int i = 1; i < k; i++) {
			a.m[i][i - 1] = 1;
		}
		while (e) {
			if (e & 1) {
				res = res * a;
			}

			e /= 2;
			a = a * a;
		}
		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans += (res.m[0][i] * b[k - i - 1]);
			ans %= mod;
		}
		return ans;
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> k;
		int b[k], c[k];
		for (i = 0; i < k; i++) {
			cin >> b[i];
		}
		for (i = 0; i < k; i++) {
			cin >> c[i];
		}
		cin >> n;
		cout << solve(b, c, k, n) << '\n';
	}
}