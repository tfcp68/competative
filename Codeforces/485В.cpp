#include <bits/stdc++.h>

using namespace std;

int main()
{
    __int64 n = 0, l, r, u, d;
    cin >> n;
    cin >> l >> u;
    r = l;
    d = u;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x > r)
        {
            r = x;
        }
        if (x < l)
        {
            l = x;
        }
        if (y > u)
        {
            u = y;
        }
        if (y < d)
        {
            d = y;
        }
    }
    __int64 b;
    b = max(abs(u - d), abs(l - r));
    cout << b * b;
    return 0;
}