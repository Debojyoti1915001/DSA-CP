class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        if(x==0&&y==0){
            return t!=1;
        }
        return x<=t&&y<=t;
    }
};