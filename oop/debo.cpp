
#include<bits/stdc++.h>
using namespace std;
void solve(string s,int i,vector<int>&vis,int c,string cur,vector<string>&ans){
    // cout<<cur<<endl;
    if(cur.size()==s.size()){
        ans.push_back(cur);
        return;
    }

    for(int j=0;j<s.size();j++){
        if(vis[j]==0){
            vis[j]=1;
            solve(s,j,vis,c+1,cur+s[j],ans);
            vis[j]=0;
        }
    }
    vis[i]=0;
}
int main() {
    // Read input from STDIN; write output to STDOUT.
    string s;
    cin>>s;
    int n=s.size();
    vector<string>ans;
    for(int i=0;i<n;i++){
        vector<int>vis(n);
        int c=1;
        string cur;
        vis[i]=1;        
        solve(s,i,vis,c,cur+s[i],ans);
        vis[i]=0;
    }
    for(auto &i:ans)cout<<i<<" ";
    return 0;
}