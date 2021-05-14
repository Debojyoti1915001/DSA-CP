#include <iostream>

using namespace std;

void spiralmatrix(int n, int a[][50])
{
int value=1,i=0,j=0,k,m;
m=n;
while(n>0)
{
a[i][j++]=value++;
for(k=1;k<=n-1;k++)
 a[i][k]=value++;

i++;j--;
for(k=1;k<=n-1;k++)
a[k][n-1-j]=value++;

for(k=1;k<=n-1;k++)
a[n-1-j][n-1-k]=value++;

for(k=1;k<=n-2;k++)
a[n-1-k][j]=value++;
i++;j++;n=n-2;
}
}
int main()
{
    int n=4;
    int a[10][50];
    spiralmatrix(n,a);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
