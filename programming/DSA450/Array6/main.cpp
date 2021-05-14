// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
#define l long long int
class Solution{
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        if(n==1)return 0;
        sort(arr,arr+n);
        l mx=arr[n-1]-k;
        l mn=arr[0]+k;
        l ans=arr[n-1]-arr[0];
        if(mx<mn)swap(mx,mn);
        for(l i=1;i<n-1;i++){
            l sb=arr[i]-k;
            l add=arr[i]+k;
            if(add<=mx||sb>=mn){
                continue;
            }if(mx-mn<=add-sb){
                mn=sb;
            }else{
                mx=add;
            }
        }
        return min(ans,mx-mn);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
