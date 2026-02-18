class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cnt1 = 0;
        int cnt0 = 0;
        int val = n&1;
        if(val == 1){
            cnt1++;
        }
        else{
            cnt0++;
        }
        int bit = -1;
        while(n){
            n = n>>1;
             val = n&1;
        if(val == 1){
            cnt1++;
            cnt0=0;
        }
        else{
            cnt0++;
            cnt1=0;
        }
        if(cnt1 == 2 || cnt0 == 2){
            return false;
        }
        }

        return true;
        
    }
};