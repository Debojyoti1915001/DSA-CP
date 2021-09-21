#include <bits/stdc++.h>
#define li long long int
using namespace std;
const li inf = 1e18 + 7;
bool check(char a)
{
    return a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
}
void solve(int i)
{
    string s;
    cin >> s;
    li visited[26] = {0}, count[26] = {0}, fv = -1, fc = INT_MIN;
    char mxV = '$', mxC = '$';
    for (auto &i : s)
    {
        count[i - 'A']++;
        if (check(i))
        {
            if (count[i - 'A'] > fv)
            {
                fv = count[i - 'A'];
                mxV = i;
            }
        }
        else if (count[i - 'A'] > fc)
        {
            fc = count[i - 'A'];
            mxC = i;
        }
    }
    if (mxV == '$' || mxC == '$')
    {
        char c = mxV == '$' ? mxC : mxV;
        if (count[c - 'A'] == s.size())
            cout << "Case #" << i << ": " << 0 << "\n";
        else
            cout << "Case #" << i << ": " << s.size() << "\n";
        return;
    }
    int mnV = 0, mnC = 0;

    for (auto &i : s)
    {
        if (check(i) && !visited[i - 'A'])
        {
            visited[i - 'A'] = 1;
            if (mxC != '$')
                mnC += count[i - 'A'];
            if (i != mxV && mxV != '$')
                mnV += 2 * count[i - 'A'];
        }
        else if (!visited[i - 'A'])
        {
            visited[i - 'A'] = 1;
            if (mxC != '$' && i != mxC)
                mnC += 2 * count[i - 'A'];
            if (mxV != '$')
                mnV += count[i - 'A'];
        }
    }
    cout << "Case #" << i << ": " << min(mnC, mnV) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    li t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}