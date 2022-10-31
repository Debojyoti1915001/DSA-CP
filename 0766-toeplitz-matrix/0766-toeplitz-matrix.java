class Solution {
    public boolean isToeplitzMatrix(int[][] m) {
        for(int i=0;i<m.length-1;i++){
            for(int j=0;j<m[0].length-1;j++){
                if(m[i][j]!=m[i+1][j+1])return false;
            }
        }
        return true;
    }
}