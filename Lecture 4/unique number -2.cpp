#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    int totxor = 0;
    for (i = 0; i < n; i++) {
        totxor = totxor ^ a[i];
    }
    for (i = 0; i < 32; i++) {
        if ( ((1 << i) & totxor) ) {
            j = i;
            break;
        }
    }
    int ans1 = 0, ans2;
    for (i = 0; i < n; i++) {
        if ((1 << j)&a[i]) {
            ans1 = ans1 ^ a[i];
        }
    }
    ans2 = totxor ^ ans1;
    if (ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << " " << ans2;
}
