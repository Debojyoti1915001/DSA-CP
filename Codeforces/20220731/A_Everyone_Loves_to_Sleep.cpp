// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        /* code */
        l n;
        cin >> n;
        l h, m;
        cin >> h >> m;
        l cur = h * 60 + m;
        l res = INT_MAX;
        for (l i = 0; i < n; i++)
        {
            l hour, minute;
            cin >> hour >> minute;
            l nxxxxxxx = hour * 60 + minute;
            if (nxxxxxxx >= cur)
            {
                res = min(res, nxxxxxxx - cur);
            }
            else
            {
                res = min(res, (24 * 60 + nxxxxxxx) - cur);
            }
        }
        cout << res / 60 << " " << res % 60 << endl;
    }
    return 0;
}
