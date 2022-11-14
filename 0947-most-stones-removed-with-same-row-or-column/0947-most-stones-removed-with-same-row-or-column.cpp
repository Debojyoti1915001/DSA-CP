class Solution {
public:
    //we take two points and find if it share its x axis or y axis
    //if it does so check if we can draw an edge 
    //just return the number of edges that can be drawn
    vector<int>parent;
    int find(int x){
        return parent[x]==x?x:find(parent[x]);
    }
    bool join(int i,int j){
        int pi=find(i);
        int pj=find(j);
        if(pi!=pj){
            parent[pi]=pj;
            return true;
        }
        return false;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent=vector<int>(n);
        for(int i=0;i<n;i++)parent[i]=i;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    if(join(i,j))c++;
                }
            }
        }
        return c;
    }
};