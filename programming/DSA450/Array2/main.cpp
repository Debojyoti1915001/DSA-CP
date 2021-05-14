#include <bits/stdc++.h>
#define l long long int
using namespace std;

int main()
{
    l n;
    cin>>n;
    l ar[n];
    l mn=1e9,mx=-1e9;
    for(l i=0;i<n;i++){
        cin>>ar[i];
        mn=min(mn,ar[i]);
        mx=max(mx,ar[i]);
    }
    cout<<"Max:"<<mx<<endl;
    cout<<"Min:"<<mn<<endl;
    return 0;
}
