#include <bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l test;
    test=1;
    while(test--){
    l n;
    cin>>n;
    vector<l> ans(n),v(n);
    for(l i=0;i<n;i++){
        cin>>v[i];
        ans[i]=0;
    }
    for(l i=1;i<n;i++){
        if(v[i]>v[i-1]){
            ans[i]=ans[i-1]+1;
        }
        else
            ans[i]=0;
    }
    cout<<*max_element(ans.begin(),ans.end())+1;
}
}
