class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dY=c[1][1]-c[0][1];
        int dX=c[1][0]-c[0][0];
        for(int i=2;i<c.size();i++){
            auto p=c[i];
            if(dX*(p[1]-c[0][1])!=dY*(p[0]-c[0][0]))return false;
        }
        return true;
    }
};