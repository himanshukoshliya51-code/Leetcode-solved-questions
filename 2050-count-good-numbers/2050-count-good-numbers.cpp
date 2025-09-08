class Solution {
public:

long long myPow(long long x , long long n){
     const long long MOD = 1000000007;
    // long long ans =1;
    if(n==0){
        return 1;
    }
    long long ans = myPow(x,n/2);
        if(n % 2 == 1){
            ans = (ans*ans*x % MOD)% MOD;
        }
        else{
            ans = (ans * ans)% MOD;
        } 
        return ans;

}


    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;
        long long ans1 = 1;
        long long ans2 = 1;
        if(n % 2 == 1){
            ans1 = myPow(5,(n+1)/2);
            ans2 = myPow(4,n/2);
        }
        else{
            ans1 = myPow(5,n/2) % MOD;
            ans2 = myPow(4,n/2) % MOD;
        }
        return (ans1*ans2)%MOD;
    }
};