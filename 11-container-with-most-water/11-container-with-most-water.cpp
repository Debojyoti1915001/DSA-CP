class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        int i=0,j=n-1;
        while(i<j){
            int area=(j-i)*min(h[i],h[j]);
            ans=max(ans,area);
            cout<<area<<" ";
            if(h[i]<h[j])i++;
            else j--;
        }
        return ans;
    }
};