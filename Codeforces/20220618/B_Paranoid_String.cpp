// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,ans;
    string S;
   cin >> n >> S, ans = n;
		for (int i = 1; i < n; ++ i)
			if (S[i] != S[i - 1])
				ans += i;
		cout << ans << '\n';
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 