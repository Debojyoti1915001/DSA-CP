// https://www.interviewbit.com/problems/painters-partition-problem/

int mod = 10000003;
int check(long long int A,long long int B, vector<int> &C,long long int Time) {
    long long int curTime = 0;
    int curPainter = 1;
    for(int i=0;i<C.size();i++) {
        if(curTime+C[i]*B>Time){
            curPainter++;
            if(curPainter>A){
                return 0;
            }
            curTime=0;
            i--;
        }else{
            curTime+=B*C[i];
        }
    }
    return 1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int lo = 0;
    long long int hi = 0;
    for(int i=0; i<C.size(); i++) hi += ((long long)B)*C[i];
    int ans;
    while(lo<=hi) {
        long long int mid = lo+(hi-lo)/2;
        if(check(A,B,C,mid)) {
            hi = mid-1;
            ans = mid%mod;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
