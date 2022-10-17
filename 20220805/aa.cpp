// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin >> n;
    vector<l> ht(n);
    for (l i = 0; i < n; i++)
        cin >> ht[i];
    vector<vector<l>>v;
    for (l i = 0; i < n; i++)
    {
        int cm;
        cin >> cm;
        ht[i] = 100 * ht[i] + cm;
        v.push_back({ht[i],i});
    }
    sort(ht.begin(),ht.end());
    l k=3,i=0,j=0;
    l mn=INT_MAX;
    char A,B;
    while(j<v.size()){
        if(j-i+1<k){
            j++;
        }else{
            if(v[j][0]-v[i][0]<mn){
                mn=v[j][0]-v[i][0];
                A=v[i][1]+'A';
                B=v[j][1]+'A';
            }
            j++;
            i++;
        }
    }
    cout<<A<<" "<<B<<endl;
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
