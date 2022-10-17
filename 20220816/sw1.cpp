// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   string s;
   getline(cin, s);
   vector<l>cnt(26);
   for(auto &i:s){
    if(isalpha(i)){
        i=tolower(i);
        cnt[i-'a']++;
    }
   }
   char ch='a';
   l mx=cnt[0];
    for(l i=1;i<26;i++){
        if(mx<cnt[i]){
            mx=cnt[i];
            ch=i+'a';
        }
    }
    cout<<ch<<"->"<<mx;
}
 
int main()
{
   solve();
    return 0;
}
 