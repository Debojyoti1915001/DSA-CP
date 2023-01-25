class Solution {
public:
    void dfs(int i,vector<int>& edges,vector<int>& m){
        int dist=0;
        while(i!=-1&&m[i]==-1){
            m[i]=dist;
            dist++;
            i=edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res=-1,mn=INT_MAX;
        int n=edges.size();
        vector<int>m1(n,-1),m2(n,-1);
        dfs(node1,edges,m1);
        dfs(node2,edges,m2);
        for(int i=0;i<n;i++){
            if(min(m1[i],m2[i])>=0&&max(m1[i],m2[i])<mn){
                mn=max(m1[i],m2[i]);
                res=i;
            }
        }
        return res;
    }
};