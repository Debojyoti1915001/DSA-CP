// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector <int>res;
            int i=0,j=0,k=0;
            while(i<n1&&j<n2){
                if(A[i]==B[j]){A[k++]=A[i];i++;j++;}
                else if(A[i]<B[j])i++;
                else j++;
            }
            i=0,j=0;
            while(i<k&&j<n3){
                if(A[i]==C[j]){
                    res.push_back(C[j]);
                    i++;
                    j++;
                    while(i<k&&A[i]==A[i-1])i++;
                    while(j<n3&&C[j]==C[j-1])j++;
                }
                else if(A[i]<C[j])i++;
                else j++;
            }
            return res;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends