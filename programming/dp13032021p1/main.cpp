#include <bits/stdc++.h>
using namespace std;
void res(string s,int l,int r){
    for(int i=l;i<=r;i++){
        //str.push_back(s.substr(l,i));
        cout<<s.substr(l,i);
    }
     if(l>=r)return;
     else
    res(s,l++,r);
}
int main()
{
//    vector<string> str,ans;
    string s;
    cin>>s;
    //ans=
    res(s,0,s.length());
// cout<<ans.size()<<endl;
//    for(int i=0;i<ans.size();i++){
//        cout<<ans[i]<<" ";
//    }
}
