#include<bits/stdc++.h>

using namespace std;

int a[100];

int binary_search(int left, int right, int val) {
    int mid = (left + right) / 2;
    if (right == left) {
        if (a[mid] == val) {
            return mid;
        }
        else {
            return -1;
        }
    }
    else if (a[mid] < val) {
        return binary_search(mid + 1, right, val);
    }
    else {

        return binary_search(left, mid, val);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    int val;
    cin >> val;
    cout << binary_search(0, n - 1, val);
}
