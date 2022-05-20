// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complete the function
        int sz=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k)sz++;
        }
        if(sz==0)return 0;
        // cout<<sz<<" ";
        int ans=n;
        int i=0,j=0,cur=0;
        while(j<n){
            if(arr[j]>k)cur++;
            if(j-i+1<sz)j++;
            else{
                ans=min(ans,cur);
                if(arr[i]>k)cur--;
                i++;
                j++;
            }
            // cout<<ans<<"; ";
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends