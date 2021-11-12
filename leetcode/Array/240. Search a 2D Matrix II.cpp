// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int row=0,col=mat[0].size()-1;
        int n=mat.size(),m=mat[0].size();
        while(row<n&&col>=0){
            if(mat[row][col]==t)return true;
            if(mat[row][col]>t)col--;
            else row++;
        }
        return false;
    }
};