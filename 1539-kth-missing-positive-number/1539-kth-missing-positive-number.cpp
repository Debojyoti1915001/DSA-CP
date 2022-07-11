class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=0,i=1,m=1;
        while(j<arr.size()){
            if(i!=arr[j]){
                if(k==m)return i;
                m++;
                i++;
            }else{
                i++;j++;
            }
        }
        return arr[arr.size()-1]+k-m+1;
    }
};