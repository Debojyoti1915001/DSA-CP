class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1000000000 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        long long int ans=-1;
        map<int,int>vdiff;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                vdiff[vFences[j]-vFences[i]]++;
            }
        }
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                if(vdiff.count(hFences[j]-hFences[i])){
                    long long int side=hFences[j]-hFences[i];
                    ans=max(ans,side%mod);
                }
            }
        }
        return ans==-1?-1:(ans*ans)%mod;
    }
};