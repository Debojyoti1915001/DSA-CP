class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(!s.count(e))return 0;
        int ans=1;
        s.erase(b);
        queue<string>q;
        q.push(b);
        while(q.size()){
            int sz=q.size();
            while(sz--){
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.size();i++){
                    string temp=cur;
                    for(char j='a';j<='z';j++){
                        temp[i]=j;
                        if(temp==e)return ans+1;
                        if(s.count(temp)){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};