#include <iostream>

using namespace std;
int print(int ar[],int n){
cout<<"In print function"<<endl;
for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
}
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    print(ar,n);
    return 0;
}
