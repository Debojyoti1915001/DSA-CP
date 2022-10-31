class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int i=0,j=m[0].size()-1;
        while(i<m.size()){
            int x,y;
            x=i,y=j;
            int cur=m[x][y];
            while(x<m.size()&&y<m[0].size()){
                if(m[x][y]!=cur)return false;
                x++,y++;
            }
            if(j==0){
                i++;
            }else{
                j--;
            }
        }
        return true;
    }
};