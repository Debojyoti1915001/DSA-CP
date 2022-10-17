// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   string s;
   cin>>s;
   int n=s.size();
   vector<int>left(n,1),right(n,1);
   for(int i=0;i<s.size();i++){
     if(i>2){
        if(s[i-1]=='1'&&s[i]=='0')
        left[i]=left[i-2]+1;
     }   
   }
   for(int i=s.size()-1;i>=0;i--){
      if(i+2<s.size()){
        if(s[i]=='0'&&s[i+1]=='1')
        right[i]=right[i+2]+1;
     }  
   }
   int ans=0;
   for(int i=0;i+2<n;i++){
    if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'){
        ans+=right[i+2];
    }else if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='1'){
        ans+=left[i];
    } 
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
 