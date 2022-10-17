// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<int> parse(string s){
    string left,right;
    int f=0;
    for(auto &i:s){
        if(i=='-'){
            f++;
        }else if(f==0){
            left+=i;
        }else{
            right+=i;
        }
    }
    return {stoi(left),stoi(right)};
}
void solve()
{
    l n,m,k;
    cin>>n>>m>>k;
    map<l,l>mp;
    for(l i=0;i<m;i++){
        l cur;
        cin>>cur;
        mp[cur]++;
    }
    l ans=0;
    for(l i=1;i<=n;i++){
        if(k>=i){
            if(mp[i]==0){
                ans++;
                k-=i;
            }
        }else break;
    }
    cout<<ans<<endl;
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
 