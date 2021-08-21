#include <bits/stdc++.h>
using namespace std;
void solve(string s)
{
    int n = s.length();
    stack<char> stk;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>' && count)
        {
            while (stk.top() != '<')
                stk.pop();
            stk.pop();
            count--;
        }
        else if (s[i] == '<')
        {
            count++;
            stk.push(s[i]);
        }
        else
        {
            stk.push(s[i]);
        }
    }
    string ans = "";
    while (stk.size())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
int main()
{
    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
