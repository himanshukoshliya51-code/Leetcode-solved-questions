class Solution {
public:
    double myPow(double x, int n) {
        // double ans = 1;
        
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        if(nn == 0){
            return 1;
        }
        double ans = myPow(x,nn/2);
        if(nn % 2 == 1){
            ans = ans*ans*x;
        }
        else{
            ans = ans * ans;
        }
         if (n < 0)  ans = (double)(1.0) / (double)(ans);


       return ans; 
    }
};