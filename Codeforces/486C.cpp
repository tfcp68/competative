#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, ans = 0;
    cin >> n >> p;
    string s;
    cin >> s;
    if (p > n / 2)
        p = n - p;
    else
        --p;
    int l = p, r = p;
    for (int i = 0; i < (n - 1) / 2; ++i)
    {
        if (s[i] != s[n - i - 1])
        {
            l = i;
            break;
        }
    }
    r = l;
    for (int i = (n - 1) / 2; i > 0; --i)
    {
        if (s[i] != s[n - i - 1])
        {
            r = i;
            break;
        }
    }
    ans = min(abs(l - r) + abs(r - (p)), abs(l - r) + abs((p)-l));
    for (int i = l; i <= r; ++i)
    {
        int temp = 0;
        temp = abs(s[i] - s[n - 1 - i]);
        if (temp > 13)
        {
            temp = 26 - temp;
        }
        ans += temp;
    }
    cout << ans << '\n';
    return 0;
}