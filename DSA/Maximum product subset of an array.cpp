#include <bits/stdc++.h>
using namespace std;
int maxProductSubset(int a[], int n)
{
    int cnt0 = 0, cntN = 0, ans = 1, productN = 1, neg = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            cnt0++;
        }
        else if (a[i] > 0)
        {
            ans *= a[i];
        }
        else
        {
            cntN++;
            neg = max(neg, a[i]);
            productN *= a[i];
        }
    }
    if (cnt0 == n)
    {
        return 0;
    }
    if (cntN % 2 == 0)
    {
        return ans * productN;
    }
    else
    {
        return ans * productN / neg;
    }
}
int main()
{
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}