#include <bits/stdc++.h>

using namespace std;
#define l long long int
int main()
{
    l n;
    cin>>n;
    l a[n];
    for(l i=0;i<n;i++){
        cin>>a[i];
    }
    l mx=a[0],curr=a[0];
    for(l i=1;i<n;i++){
        mx=max(a[i],mx+a[i]);
        curr=max(curr,mx);
    }
    cout<<curr<<endl;
    return 0;
}
