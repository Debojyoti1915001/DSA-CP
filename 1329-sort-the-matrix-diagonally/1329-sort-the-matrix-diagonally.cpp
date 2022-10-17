class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int si=0,sj=m-1;
        while(si!=n){
            int i=si,j=sj,k=0;
            vector<int>temp;
            while(i<n&&j<m){
                temp.push_back(mat[i++][j++]);
            }
            sort(temp.begin(),temp.end());
            i=si,j=sj;
            while(i<n&&j<m){
                mat[i++][j++]=temp[k++];
            }
            if(sj>0)sj--;
            else si++;
        }
        return mat;
        
    }
};