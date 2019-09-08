#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

// (a^b)%mod
int powr(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return res;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cout << powr(2, 3, 5);

	}
}