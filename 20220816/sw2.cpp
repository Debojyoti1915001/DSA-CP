// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
bool canPairs(vector<l>arr, l n,l k)
{
    if (n & 1)
        return false;
 
    unordered_map<l, l> freq;
 
    for (int i = 0; i < n; i++)
        freq[((arr[i] % k) + k) % k]++;
 
    for (int i = 0; i < n; i++) {
        int rem = ((arr[i] % k) + k) % k;
 
        if (2 * rem == k) {
            if (freq[rem] % 2 != 0)
                return false;
        }
 
        else if (rem == 0) {
            if (freq[rem] & 1)
                return false;
        }
 
        else if (freq[rem] != freq[k - rem])
            return false;
    }
    return true;
}
l stollFun(string n){
    l k=0;
    for(auto &i:n){
        k=k*10+(i-'0');
    }
    return k;
}
void solve()
{
    l n,k;
    string s,s1;
    getline(cin,s);
    getline(cin,s1);
    vector<l>v;
    string cur;
    for(auto &i:s){
        if(isdigit(i)){
            cur+=i;
        }else{
            // cout<<cur<<" ";
            v.push_back(stollFun(cur));
            cur="";
        }
    }
    v.push_back(stollFun(cur));
    k=stoll(s1);
    n=v.size();
    // for(auto &i:v)cout<<i<<" ";
    // cout<<k<<endl;
   if(canPairs(v,n,k)){
    cout<<"true";
   }else{
    cout<<"false";
   }
}
 
int main()
{
    solve();
    return 0;
}
 