#include <bits/stdc++.h>
#define l long long int
using namespace std;
stack<char> st;
char reversing(){
char c;
   c=st.top();
     st.pop();
if(!st.empty()){
    reversing();
}
st.push(c);
}

string reverse(string s){
for(l i=0;i<s.length();i++){
st.push(s[i]);
}
string ans;
reversing();
for(l i=0;i<s.length();i++){
char c=st.top();
st.pop();
  ans+=c;
}
return ans;
}

int main()
{
    string s,ans;
    cin>>s;
    ans=reverse(s);
    cout<<ans;
}
