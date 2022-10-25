class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.size(),start=-1,len=INT_MAX,c=0;
        vector<int>cnt(256);
        for(auto &i:t){
            if(cnt[i]==0)c++;
            cnt[i]++;
        }
        while(j<n){
            cnt[s[j]]--;
            if(cnt[s[j]]==0)c--;
            while(c==0){
                if(len>j-i+1){
                    len=j-i+1;
                    start=i;
                }
                cnt[s[i]]++;
                if(cnt[s[i]]>0)c++;
                i++;
            }
            j++;
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};