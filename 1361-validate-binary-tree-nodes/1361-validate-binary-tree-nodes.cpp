class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>in(n);
        for(auto &i:leftChild){
            if(i!=-1)in[i]++;
        }
        for(auto &i:rightChild){
            if(i!=-1)in[i]++;
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                if(root!=-1)return false;
                root=i;
            }
        }
        vector<int>vis(n);
        queue<int>q;
        if(root==-1)return false;
        q.push(root);
        while(q.size()){
            int t=q.front();
            cout<<t<<" ";
            q.pop();
            if(vis[t])return false;
            vis[t]=1;
            if(leftChild[t]!=-1)q.push(leftChild[t]);
            if(rightChild[t]!=-1)q.push(rightChild[t]);
        }
        return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};