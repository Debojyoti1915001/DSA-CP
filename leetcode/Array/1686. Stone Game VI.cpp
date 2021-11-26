// https://leetcode.com/problems/stone-game-vi/

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>>v;
        int n=a.size();
        for(int i=0;i<n;i++){
            v.push_back({a[i]+b[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int alice=0,bob=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                alice+=a[v[i].second];
            }else{
                bob+=b[v[i].second];
            }
        }
        cout<<alice<<" "<<bob;
        if(alice>bob)return 1;
        else if(alice<bob)return -1;
        return 0;
    } 
};