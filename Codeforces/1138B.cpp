#include <bits/stdc++.h>

using namespace std;

int clown[5000], acr[5000], n;

void solve(int a, int b, int c, int d)
{
    for (int i = 0; i < n; ++i)
    {
        if (acr[i] == 0 and clown[i] == 0 and a)
        {
            cout << i + 1 << ' ';
            --a;
        }
        else if (acr[i] == 0 and clown[i] == 1 and c)
        {
            cout << i + 1 << ' ';
            --c;
        }
        else if (acr[i] == 1 and clown[i] == 0 and b)
        {
            cout << i + 1 << ' ';
            --b;
        }
        else if (acr[i] == 1 and clown[i] == 1 and d)
        {
            cout << i + 1 << ' ';
            --d;
        }
    }
    return;
}

int main()
{
    int an = 0, bn = 0, cn = 0, dn = 0, a = 0, b = 0, c = 0, d = 0;
    bool ans = false;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        clown[i] = s[i] - '0';
    }
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        acr[i] = s[i] - '0';
        if (acr[i] == 0)
        {
            if (clown[i] == 0)
                ++an;
            else
                ++cn;
        }
        else
        {
            if (clown[i] == 0)
                ++bn;
            else
                ++dn;
        }
    }
    // cout<<an<<' '<<bn<<' '<<cn<<' '<<dn<<'\n';
    for (int i = 0; i <= bn; ++i)
    {
        for (int j = 0; j <= cn; ++j)
        {
            b = i;
            c = j;

            d = (dn - c + b) / 2;
            a = (n / 2) - d - c - bn + b;
            // cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
            if (d >= 0 and a >= 0)
            {
                if (a <= an and b <= bn and c <= cn and d <= dn)
                {
                    if (c + d == dn - d + b and a + (bn - b) + c + d == n / 2)
                    {
                        solve(a, bn - b, c, d);
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}