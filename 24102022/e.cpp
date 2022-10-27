// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<int> Prefix_Mex(vector<int>& A,int j, int n)
{
    int mx_element = *max_element(A.begin()+j, A.end());
 
    set<int> s;
    for (int i = 0; i <= mx_element + 1; i++) {
        s.insert(i);
    }
 
    vector<int> B(n,-1);
    for (int i = j; i < n; i++) {
 
        auto it = s.find(A[i]);
 
        if (it != s.end())
            s.erase(it);
 
        B[i] = *s.begin();
    }
 
    return B;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    int j=0;
    while(j<n-1){
        vector<int>pre=Prefix_Mex(v,j,v.size());
        // for(auto &i:pre)cout<<i<<" ";
        // cout<<endl;
        j=n-1;
        cout<<pre[j]<<endl;
        if(pre[j]==0)break;
        while(j>1&&pre[j]==pre[j-1])j--;
        // cout<<j<<endl;
        j++;
    }
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
 