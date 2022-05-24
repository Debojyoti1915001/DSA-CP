class Solution {
public:
    vector<int> NSL(vector<int>& arr, int n){
        stack<pair<long long,int>> s;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()>0&&s.top().first>=arr[i]){
                while(s.size()>0&&s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }else{
                    v.push_back(s.top().second);
                }
            }else{
                v.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        return v;
    }
    vector<int> NSR(vector<int>& arr, int n){
        stack<pair<long long,int>> s;
        vector<int>v;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                v.push_back(n);
            }
            else if(s.size()>0&&s.top().first>=arr[i]){
                while(s.size()>0&&s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(n);
                }else{
                    v.push_back(s.top().second);
                }
            }else{
                v.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector <int> l=NSL(arr,n);
        vector <int> r=NSR(arr,n);
        long long ans=0;
        for(int i=0;i<n;i++){
            //cout<<i<<"->"<<r[i]<<" "<<l[i]<<endl;
            ans=max(ans,(long long)((r[i]-l[i]-1)*arr[i]));
        }
        return ans;
        
    }
};