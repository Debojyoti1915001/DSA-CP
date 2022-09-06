class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        vector<int>visited(n);
        visited[0]=1;
        queue<int>q;
        q.push(0);
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int idx=q.front();
                q.pop();
                if(idx==n-1)return steps;
                vector<int>&next=m[arr[idx]];
                next.push_back(idx+1);
                next.push_back(idx-1);
                for(int j:next){
                    if(j>=0&&j<n&&visited[j]==0){
                    q.push(j);
                    visited[j]=1;
                    }
                }
                next.clear();
            }
            steps++;
        }
        return 0;
    }
};