class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ads) {
        vector<int>res(ads.size()+1,INT_MIN);
        int f=-1,l=-1;
        unordered_map<int,vector<int>>m;
        for(auto v:ads){
            int a=v[0],b=v[1];
            m[a].push_back(b);
            m[b].push_back(a);
        }
        unordered_map<int,int>vis;
        for(auto [a,b]:m){
            if(b.size()==1){
                vis[a]=1;
                if(f==-1)f=a;
                else{
                    l=a;
                    break;
                }
            }
        }
        res[0]=f;
        res.back()=l;
        for(int i=1;i<res.size()-1;i++){
            for(auto j:m[res[i-1]]){
                if(!vis[j]){
                    res[i]=j;
                    vis[j]=1;
                    break;
                }
            }
        }
        return res;
    }
};