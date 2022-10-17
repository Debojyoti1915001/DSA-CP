#include<bits/stdc++.h>
using namespace std;

int find(string& s){
  int n=s.length();
  int cnt=0;
  for(auto x:s){
    if(x=='*') cnt++;
  }
  
  int ans=0;
  int l=0,r=n-1;
  while(l<r){
    if(s[l]=='' && s[r]==''){
      cnt-=2;
      ans+=(r-l-1)-cnt;
      l++;
      r--;
    }
    else if(s[l]!='*') l++;
    else r--;
  }
  return ans;
}
int solve(string& s,char ch){
  int n=s.length();
  int i=0,j=0,ans=0;
  while(j<n){
    if(s[j]==ch){
      ans+=j-i;
      i++;
    }
    j++;
  }
  return ans;
}
int main(){
  int n;
  cin>>n;
  string s;
  for(int i=0;i<n;i++){
    char ch;
    cin>>ch;
    s.push_back(ch);
  }
  
  char c1,c2;
  cin>>c1>>c2;
  
  string odr;
  for(int i=0;i<n;i++){
    if(s[i]==c1 || s[i]==c2){
      odr.push_back(s[i]);
      s[i]='*';
    }
  }
  
  int ans=find(s);
  ans += min(solve(odr,c1),solve(odr,c2));
  cout<<ans<<endl;
  return 0;
}