//My Template for fenwick tree
    #define MAX 200005
    long long bit[MAX];
    long long query(int indx) {
        long long sum = 0;
        while (indx) {
            sum += bit[indx];
            indx -= (indx & -indx);
        }
        return sum;
    }

    void update(int indx, int x) {
        assert(indx != 0);
        while (indx < MAX) {
            bit[indx] += x;
            indx += (indx & -indx);
        }
    }
	//Template ends
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //use BIT or fenwick tree
        //firs of all let me make all elements relative indexed
        for(int i=0;i<MAX;i++){
            bit[i]=0;
        }
		  // Converts an array to an array with values from 1 to n
    // and relative order of smaller and greater elements remains
    // same.  For example, {7, -90, 100, 1} is converted to
    // {3, 1, 4 ,2 }
        vector<int> b(nums.begin(),nums.end());
        sort(b.begin(),b.end());
        for(int i=0;i<nums.size();i++){
            nums[i]=lower_bound(b.begin(),b.end(),nums[i])-b.begin()+1;
        }
       
        vector<int> res(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            res[i]=query(nums[i]-1);
            update(nums[i],1);
        }
        return res;
    }
};