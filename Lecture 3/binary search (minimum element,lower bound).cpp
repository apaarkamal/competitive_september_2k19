int binsearch(int lo, int hi)
{
    //lo is included
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}