int lf = 0, rt = 1e15;
while (lf <= rt) {
    int mid = (lf + rt) / 2;
    if (check(mid)) {
        ans = mid;
        lf = mid + 1;
    }
    else {
        rt = mid - 1;
    }
}
cout << ans;