class Solution {
public:
    int minBitFlips(int start, int goal) {
        int s1 = start^goal;
        int cnt =0;
        while(s1){
            s1 = s1&(s1-1);
            cnt++;

        }
        
        return cnt;
    }
};