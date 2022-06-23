class Solution {
public:
    vector<int>parent;
    int find(int x){
        return parent[x]==x?x:find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        parent=vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int extra=0;
        for(auto x:c){
            int p1=find(x[0]);
            int p2=find(x[1]);
            if(p1==p2){
                extra++;
            }else parent[p1]=p2;
        }
        int islands=0;
        for(int i=0;i<n;i++)if(parent[i]==i)islands++;
        //since islands-1 no of connections are reqd
        return (extra>=islands-1)?islands-1:-1;
    }
};