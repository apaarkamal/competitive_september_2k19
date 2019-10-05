#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 500000;

vector<P> gr[N];//{node,dis}

bool vis[N];
int mindis[N];
int dijsktra(int src, int des) {
	priority_queue<P, vector<P>, greater<P>> Q;
	for (int i = 0; i < N; i++) {
		mindis[i] = INT_MAX;
		vis[i] = false;
	}

	Q.push({0, src}); //{dis,node}
	while (!Q.empty()) {
		P tp = Q.top();
		Q.pop();
		int cur = tp.S;
		int dis = tp.F;
		if (vis[cur]) continue;
		vis[cur] = true;
		mindis[cur] = dis;

		for (auto x : gr[cur]) {
			Q.push({mindis[cur] + x.S, x.F});
		}
	}
	return mindis[des];
}

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

	}
}