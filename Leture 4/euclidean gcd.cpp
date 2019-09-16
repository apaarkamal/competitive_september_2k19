#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	return gcd(b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//  code starts
	cout << gcd(5, 7);
}
