// https://leetcode.com/problems/unique-substrings-in-wraparound-string/

cnt[i] stores the number of unique substring ending at character 'a'+i. For example cnt[3] will count how many unique substrings ending with d are there. The condition p[i-1]-p[i]==25 is when we encount substring like .....za....

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26,0);
        int n=p.length();
        int mx=1;
        for(int i=0;i<n;i++)
        {
            if(i>0 and (p[i]-p[i-1]==1 or p[i-1]-p[i]==25))
                mx++;
            else
                mx=1;
            cnt[p[i]-'a']=max(cnt[p[i]-'a'],mx);
        }
        int ans=0;
        for(int i=0;i<26;i++)ans+=cnt[i];
        return ans;
    }
};