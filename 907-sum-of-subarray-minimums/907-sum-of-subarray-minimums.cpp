class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        int n=v.size();
        vector<int>left,right;
        stack<pair<int,int>>s1,s2;
        for(int i=n-1;i>=0;i--){
            while(s1.size()&&s1.top().first>v[i]){
                s1.pop();
            }
            if(s1.size())
                right.push_back(s1.top().second);
            else
                right.push_back(n);
            
            s1.push({v[i],i});
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++){
            while(s2.size()&&s2.top().first>=v[i]){
                s2.pop();
            }
            if(s2.size())
                left.push_back(s2.top().second);
            else
                left.push_back(-1);
            
            s2.push({v[i],i});
        }
        int sum=0,mod=1e9 +7;
        for(int i=0;i<n;i++){
            int l=left[i];
            int r=right[i];
            long long int val1=((i-l)*v[i])%mod;
            long long int val2=((r-i)*val1)%mod;
            sum=(sum+val2)%mod;
        }
        return sum%mod;
    }
};