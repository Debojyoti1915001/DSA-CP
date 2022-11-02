class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int>vis;
        for(auto &i:bank)vis[i]=1;
        queue<string>q;
        q.push(start);
        int steps=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                string t=q.front();
                q.pop();
                if(t==end)return steps;
                for(int i=0;i<t.size();i++){
                    for(char j='A';j<='Z';j++){
                        if(t[i]!=j){
                            char temp=t[i];
                            t[i]=j;
                            if(vis[t]){
                                q.push(t);
                                vis[t]=0;
                            }
                            t[i]=temp;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};