#include <iostream>

using namespace std;
void stf(string s,int n,string curr=" ",int index=-1){
if(index==n){
    return;
}
for(int i=index+1;i<n;i++){
    curr+=s[i];
    cout<<curr<<" ";
    stf(s,n,curr,i);
    curr=curr.erase(curr.size()-1);
}
return;
}

void st(string s){
 stf(s,s.length());
}
int main()
{
    string s;
    cin>>s;
    st(s);
}
