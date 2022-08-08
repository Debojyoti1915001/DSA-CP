class Solution {
public:
    int find(vector<int>parent,int x){
        return x==parent[x]?x:find(parent,parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &i:edges){
            int p1=find(parent,i[0]-1);
            int p2=find(parent,i[1]-1);
            if(p1!=p2){
                parent[p1]=p2;
            }else return i;
        }
        return {-1,-1};
    }
};