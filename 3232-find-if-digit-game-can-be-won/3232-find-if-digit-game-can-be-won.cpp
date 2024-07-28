class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s=0,d=0,h=0;
        for(auto &i:nums){
            if(i>=10&&i<=99)d+=i;
            else if(i<=9)s+=i;
            else h+=i;
        }
        if(s>h+d||d>s+h)return true;
        return false;
    }
};