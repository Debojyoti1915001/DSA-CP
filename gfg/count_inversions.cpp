// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long int
ll merge(ll ar[],ll B[],ll L,ll mid,ll R){
    ll inv=0;
    ll i=L,j=mid,k=L;
    while(i<=mid-1&&j<=R){
        if(ar[i]<=ar[j]){
            B[k++]=ar[i++];
        }
        else if(ar[i]>ar[j]){
            inv+=mid-i;
            B[k++]=ar[j++];
        }
    }
    while(i<=mid-1){
        B[k++]=ar[i++];
    }
    while(j<=R){
        B[k++]=ar[j++];
    }
    for(ll i=L;i<=R;i++){
        ar[i]=B[i];
    }
    return inv;
}
ll mergeSort(ll arr[],ll temp[],ll L,ll R){
    ll inv=0;
    while(L<R){
        ll mid=(L+R)/2;
        inv+=mergeSort(arr,temp,L,mid);
        inv+=mergeSort(arr,temp,mid+1,R);
        inv+=merge(arr,temp,L,mid,R);
    }
    return inv;
}
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ll temp[N];
        return mergeSort(arr,temp,0,N-1);
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends