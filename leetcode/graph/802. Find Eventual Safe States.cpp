// https://leetcode.com/problems/find-eventual-safe-states/

***
C++
***
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       //find all the nodes thats not part of any cycle
        //0->not visited
        //1->safe
        //2->unsafe
        vector<int>res;
        int n=graph.size();
        if(n==0)return res;
        vector<int>color(n);
        for(int i=0;i<n;i++){
            if(dfs(graph,i,color))res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int>>& graph,int start,vector<int>&color){
        if(color[start]!=0)return color[start]==1;
        color[start]=2;
        for(auto ele:graph[start]){
            if(!dfs(graph,ele,color)){
                return false;
            }
        }
        color[start]=1;
        return true;
    }
};

***
JAVA
***

class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer>res=new ArrayList<>();
        if(graph==null||graph.length==0)return res;
        int n=graph.length;
        int[]color=new int[n];
        for(int i=0;i<n;i++){
            if(dfs(graph,i,color))res.add(i);
        }
        return res;
    }
    public boolean dfs(int[][] graph,int start,int[]color){
        if(color[start]!=0)return color[start]==1;
        color[start]=2;
        for(int ele:graph[start]){
            if(!dfs(graph,ele,color))return false;
        }
        color[start]=1;
        return true;
    }
}