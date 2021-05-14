#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin, s);
        int hr = ((int)s[0] - '0') * 10 + (int)s[1] - '0';
        int mn = ((int)s[3] - '0') * 10 + (int)s[4] - '0';
        int tm = to_string(s[6] + s[7]) == "AM" ? hr : hr + 12;
        int n;
        cin >> n;
        while (n--)
        {
            string c;
            getline(cin, c);
            int hr1 = ((int)c[0] - '0') * 10 + (int)c[1] - '0';
            int mn1 = ((int)c[3] - '0') * 10 + (int)c[4] - '0';
            int tm1 = to_string(c[6] + c[7]) == "AM" ? hr1 : hr1 + 12;
            string r;
            getline(cin, r);
            int hr2 = ((int)r[0] - '0') * 10 + (int)r[1] - '0';
            int mn2 = ((int)r[3] - '0') * 10 + (int)r[4] - '0';
            int tm2 = to_string(r[6] + r[7]) == "AM" ? hr2 : hr2 + 12;
            if (hr >= hr1 && hr <= hr2 && mn >= mn1 && mn <= mn2)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    return 0;
}
