// https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int hi=n,lo=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if((mid==1||isBadVersion(mid-1)==false)&&isBadVersion(mid)==true)return mid;
            if(!isBadVersion(mid))lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};