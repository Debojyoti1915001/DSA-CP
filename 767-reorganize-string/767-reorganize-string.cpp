class Solution {
public:
    string reorganizeString(string s) {
        vector<int>cnt(26);
        for(auto c:s){
            cnt[c-'a']++;
        }
        priority_queue<pair<int,int>>pq;//max heap
        for(int i=0;i<26;i++){
            if(cnt[i]){
                pq.push({cnt[i],i});
            }
        }
        string ans;
        while(pq.size()>1){
            auto [count1,s1]=pq.top();
            pq.pop();
            auto [count2,s2]=pq.top();
            pq.pop();
            count1--;
            count2--;
            ans+='a'+s1;
            ans+='a'+s2;
            if(count1){
                pq.push({count1,s1});
            }
            if(count2){
                pq.push({count2,s2});
            }
        }
        if(pq.size()==1){
            auto[a,b]=pq.top();
            pq.pop();
            if(a>1){
                return "";
            }
            ans+=b+'a';
        }
        return ans;
    }
};