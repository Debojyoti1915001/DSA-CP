// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    vector<l>left(m+1),right(m+1);
    for(l i=0,j=0;i<m;i++,j++){
        while(j<n&&a[j]!=b[i])j++;
        left[i]=j;
    }
    for(l i=m-1,j=n-1;i>=0;i--,j--){
        while(j>=0&&a[j]!=b[i])j--;
        right[i]=j;
    }
    l ans=0;
    for(l i=0;i<m;i++){
        ans=max(ans,right[i+1]-left[i]);
    }
    cout<<ans;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 