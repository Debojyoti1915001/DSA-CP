#include<stdio.h>
#include<stdlib.h>
#include<time.h>

///let upper limit be 100
///and lower limit be 0
int ul = 100;
int ll = 0;

void rvereseArray(int *arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
int n,k;
printf("ENTER SIZE OF ARRAY : ");
scanf("%d", &n);
printf("ENTER SIZE OF SUBARRAY 'K':");
scanf("%d",&k);

if(k>n){
    printf("\nK cannot be greater than N\n");
    return 0;
}

int *arr = (int*)malloc(n*sizeof(int));
int i,j;

srand(time(0));
for(i=0;i<n;i++){
    arr[i] = (rand()%(ul-ll+1))+ll;
}
printf("\n RANDOM ARRAY : ");
for(i=0;i<n;i++){
   printf("%d ", arr[i]);
}
printf("\n");
int c;
int* subarr = (int*)malloc(k*sizeof(int));
for(i=0;i<=n-k;i++){
    c = 0;
    for(j=i;j<i+k;j++){
        subarr[c] = arr[j];
        c++;
    }
    printf("\nSUBARRAY : ");
    for(j=0;j<k;j++){
        printf("%d ", subarr[j]);
    }
    printf("\nREVERSE :");
    rvereseArray(subarr, 0, k-1);
    for(j=0;j<k;j++){
        printf("%d ", subarr[j]);
    }
    printf("\n");

}

return 0;
}
