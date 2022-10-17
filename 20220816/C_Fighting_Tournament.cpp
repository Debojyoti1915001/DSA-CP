// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n,q;
    cin>>n>>q;
 
    vector<ll> arr(n);
    ll mxPos = 0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==n){
            mxPos = i;
        }
    }      
 
    map<ll,pair<ll,ll>> wins;
 
    ll l = 0;
    ll r = 1;
 
    ll round = 1;
 
    while(r<n){
        if(arr[r]>arr[l]){
            l = r;
            wins[r].first++;
            wins[r].second = round;
        }
        else{
            wins[l].first++;
            wins[l].second = round;
        }
        round++;
        r++;
    }
 
    while(q--){
        ll p,r;
        cin>>p>>r;
        p--;
        if(wins[p].first==0){
            cout<<0<<endl;
            continue;
        }
        ll roundsReqToWinThisMuch = wins[p].second;
        if(r>=roundsReqToWinThisMuch){
            if(p==mxPos)cout<<wins[p].first+r-roundsReqToWinThisMuch<<endl;
            else 
            cout<<wins[p].first <<endl;
        }else{
            ll diff = roundsReqToWinThisMuch - r;
            cout<<max(0ll,wins[p].first - diff)<<endl;
        }
    }
}
 
 
int main()
{
    int t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 