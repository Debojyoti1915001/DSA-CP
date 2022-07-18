#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{

    l x, y;
    cin >> x >> y;
    vector<l> res;
    res.push_back(2);
    if (x % 2 && y % 2)
    {
        //c=2
        l a = x ^ 2;
        res.push_back(a);
        l b = y ^ 2;
        res.push_back(b);
    }
    else
    {
        if (x % 2)
        {
            l a = x ^ 2;
            l b = y ^ a;
            res.push_back(a);
            res.push_back(b);
        }
        else
        {
            l a = y ^ 2;
            l b = x ^ a;
            res.push_back(a);
            res.push_back(b);
        }
    }

    sort(res.begin(), res.end());

    for (auto x : res)
        cout << x << " ";

    cout << endl;
}

int main()
{

    l test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}