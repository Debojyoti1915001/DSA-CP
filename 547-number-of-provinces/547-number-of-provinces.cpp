class Solution {
public:
    int find(vector<int>parent,int i){
        return parent[i]==i?i:find(parent,parent[i]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int groups=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    int p1=find(parent,i);
                    int p2=find(parent,j);
                    if(p1!=p2){
                        groups--;
                        parent[p1]=p2;
                    }
                }
            }
        }
        return groups;
    }
};