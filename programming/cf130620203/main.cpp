#include <bits/stdc++.h>
using namespace std;
#define l long long int
l n,k,a,b;
l dp(l x){
if(x==1||x<k){
    return a*(x-1);
}
if(x%k){
    return a*(x%k)+dp(x-x%k);
}
return dp(x/k)+min(a*(x-n/k),b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l test;
    test=1;
    while(test--){

            cin>>n>>k>>a>>b;
            cout<<dp(n);
        }
}
