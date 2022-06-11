class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,ans=INT_MAX,cnt=0,l=0;
        for(int i=0;i<nums.size();i++){
            if(x>sum){
                sum+=nums[i];
                cnt++;
                l++;
                // cout<<sum<<endl;
                if(x==sum){
                    ans=min(ans,cnt);
                }
            }else break;
        }
        l--;
        // cout<<"Yes"<<endl;
        for(int i=nums.size()-1;i>l;i--){
            sum+=nums[i];
            // cout<<sum<<endl;
            cnt++;
            while(sum>x&&l!=-1){
                sum=sum-nums[l];
                cnt--;
                l--;
                if(l==-1){
                    break;
                }
            }
            if(x==sum){
                ans=min(ans,cnt);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};