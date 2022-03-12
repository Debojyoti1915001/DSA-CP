// https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
       vector<vector<int>> v;
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) v.push_back({l,u});
            if(A[i][1] < B[j][1])   i++;
            else j++;
        }
        return v; 
    }
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>res;
        int i=0,j=0;
        while(i<A.size()&&j<B.size()){
            if(A[i][0]<=B[j][1]&&A[i][1]>=B[j][0]){
                int mn=max(A[i][0],B[j][0]);
                int mx=min(A[i][1],B[j][1]);
                res.push_back({mn,mx});
            }
            if(A[i][1]<=B[j][1]){
                i++;
            }else{
                j++;
            }
            
        }
        return res;
    }
};