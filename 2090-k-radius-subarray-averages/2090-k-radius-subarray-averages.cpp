class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        int n=v.size();
        vector<long long int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(v[i]);
        }
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i<k||(n-k)<=i){
                ans.push_back(-1);
            }
            else if(i==k){
                ans.push_back(nums[i+k]/(2*k+1));
            }else{
                ans.push_back((nums[i+k]-nums[i-k-1])/(2*k+1));
            }
        }
        return ans;
    }
};