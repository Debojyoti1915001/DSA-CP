int ans=0;
void dfs(int arr[],int m[],int n,int idx){
    if(idx==n){
        for(int i=0;i<=n;i++){
            if(i==n)ans++;
            else if(arr[i]%(i+1)!=0&&(i+1)%arr[i]!=0){
                return;
            }
        }
        return;
    }
    for(int curVal=1;curVal<=n;curVal++){
        if(m[curVal]==0){
            if((idx+1)%(curVal)!=0&&curVal%(idx+1)!=0)continue;
            m[curVal]=1;
            arr[idx]=curVal;
            dfs(arr,m,n,idx+1);
            m[curVal]=0;
        }
    }
}
int countArrangement(int n){
    ans=0;
    int arr[16],m[16]={};
    if(n==1)return 1;
    dfs(arr,m,n,0);
    return ans;
}