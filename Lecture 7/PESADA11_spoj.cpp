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
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n ;
		int a[n][n];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (k = 0; k < n; k++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					// main part of algorithm as explained
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
		// a[i][j] repressent shortedt path between i and j;
	}
}
