#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100;

int grid[N][N], n;

void init() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			grid[i][j] = 0;
		}
	}
}

void print() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (grid[i][j]) cout << "Q ";
			else cout << ". ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool check(int row, int col) {
	int i, j;
	// check up
	i = row; j = col;
	while (i >= 0) {
		if (grid[i][j] == 1) return false;
		i--;
	}
	// check left diagonal
	i = row; j = col;
	while (j >= 0 && i >= 0) {
		if (grid[i][j] == 1) return false;
		j--; i--;
	}
	// check right diagonal
	i = row; j = col;
	while (j < n && i >= 0) {
		if (grid[i][j] == 1) return false;
		j++; i--;
	}
	return true;
}

void nqueen(int row, int col) {
	if (row == n && col == 0) {
		print();
		exit(0);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(row, i)) {
			grid[row][i] = 1;
			nqueen(row + 1, 0);
			grid[row][i] = 0;
		}
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		init();
		cin >> n;
		nqueen(0, 0);
	}
}