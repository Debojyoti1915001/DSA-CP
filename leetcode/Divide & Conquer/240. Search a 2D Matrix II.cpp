// https://leetcode.com/problems/search-a-2d-matrix-ii/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row=0,col=m[0].size()-1;
        while(row<m.size()&&col>=0){
            if(m[row][col]==target){
                return true;
            }else if(m[row][col]>target)col--;
            else row++;
        }
        return false;
    }
};