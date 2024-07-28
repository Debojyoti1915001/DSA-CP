class Solution {
public:
    map<int,int>prime;
    bool isPrime(int i){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0)return false;
        }
        return true;
    }
    void primeTracker(int x,int y){
        prime[2]++;
        for(int i=max(x,3);i<=y;i++){
            if(isPrime(i))prime[i]++;
        }
    }
    int nonSpecialCount(int l, int r) {
        primeTracker(sqrt(l),sqrt(r));
        int psq=0;
        for(int i=sqrt(l);i<=sqrt(r);i++){
            if(prime[i]&&l<=(i*i)&&(i*i)<=r)psq++;
            // cout<<i<<" "<<psq<<endl;
        }
        return r-l+1-psq;
    }
};