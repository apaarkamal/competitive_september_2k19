#include<bits/stdc++.h>

using namespace std;

const int N = 1001;

string s[N];
int n, m;
int grid[N][N];

void print() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}

void go(int row, int col) {
	// cout<<row<<" "<<col<<'\n';
	// print();
	// cout<<'\n';
	if (row == n - 1 && col == m - 1) {
		print();
		exit(0);
	}
	if (col + 1 < m && s[row][col + 1] != 'X') {
		grid[row][col + 1] = 1;
		go(row, col + 1);
		grid[row][col + 1] = 0;
	}
	if (row + 1 < n && s[row + 1][col] != 'X') {
		grid[row + 1][col] = 1;
		go(row + 1, col);
		grid[row + 1][col] = 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//  code starts
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (s[0][0] == 'O') {
		grid[0][0] = 1;
		go(0, 0);
	}
	cout << -1;
}
