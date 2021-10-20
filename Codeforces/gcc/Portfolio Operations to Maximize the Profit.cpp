#include <bits/stdc++.h>
using namespace std;
#define l long long int
l portfolio_profit_maximisation(l mx, vector<l> a, vector<l> b) {
    //write your code here
    l n=a.size();
    l m=b.size();
    for(l i=1;i<n;i++)a[i]=a[i]+a[i-1];
    for(l i=1;i<m;i++)b[i]=b[i]+b[i-1];
    l ans=0;
    if(a[n-1]<mx)ans=max(ans,n);
    if(b[m-1]<mx)ans=max(ans,m);
    if(a[n-1]+b[m-1]<mx)ans=max(ans,m+n);
    for(l i=0;i<n;i++){
        l cur=i+lower_bound(b.begin(),b.end(),mx-a[i])-b.begin();
        // cout<<cur<<endl;
        ans=max(cur,ans);
    }
    // cout<<ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    l n, m, x;
    cin >> n >> m >> x;

    vector<l> a(n);
    vector<l> b(m);

    for (l i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (l i = 0; i < m; ++i) {
        cin >> b[i];
    }
    l result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}