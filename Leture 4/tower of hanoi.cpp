#include <bits/stdc++.h>
using namespace std;

void printHanoiSteps(int n, char src, char dest, char helper) {
    if (n == 0) return;

    printHanoiSteps(n - 1, src, helper, dest);
    cout << n << ": " << src << "-->" << dest << endl;
    printHanoiSteps(n - 1, helper, dest, src);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    printHanoiSteps(n, 'A', 'B' , 'C');
}