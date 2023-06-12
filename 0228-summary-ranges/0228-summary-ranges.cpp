class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) 
        {
            int first=0,last=0,x=0, size=nums.size(); vector<string> ans;
            while(x<size)
            {   
                last=x;
                if(x==size-1 || nums[x]+1 != nums[x+1])     //range termination conditions
                {
                    string s="";
                    first==last? s=to_string(nums[x]): s=to_string(nums[first])+"->"+to_string(nums[last]);
                    ans.push_back(s);
                    first=x+1;  //start of a new range
                }
                x++;
            }
            return ans;
        }
};
