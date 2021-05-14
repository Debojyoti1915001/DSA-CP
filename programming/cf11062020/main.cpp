#include <bits/stdc++.h>
#define l long long int
using namespace std;

int main()
{
    l n,m;
    cin>>n>>m;
    vector<l> v;
    for(l i=0;i<n;i++){
        l a;
        cin>>a;
        if(a<0){
            v.push_back(a);
        }
    }
    sort(v.begin(),v.end());
    l sum=0;
    for(l i=0;i<m&&i<v.size();i++){
        sum-=v[i];
    }
    cout<<sum;
}
