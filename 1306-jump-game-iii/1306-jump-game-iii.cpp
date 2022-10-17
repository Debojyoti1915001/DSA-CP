class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        map<int,int>vis;
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(q.size()){
            int t=q.front();
            q.pop();
            if(arr[t]==0)return true;
            int left=t-arr[t];
            int right=t+arr[t];
            if(!vis.count(left)&&left>=0&&left<arr.size()){
                vis[left]=1;
                q.push(left);
            }
            if(!vis.count(right)&&right>=0&&right<arr.size()){
                vis[right]=1;
                q.push(right);
            }
        }
        return false;
    }
};