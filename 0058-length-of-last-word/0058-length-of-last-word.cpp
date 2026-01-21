class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        int cntprev = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(cnt > 0) {          // word just ended
                    cntprev = cnt;
                    cnt = 0;
                }
            } else {
                cnt++;
            }
        }

        return (cnt > 0) ? cnt : cntprev;
    }
};
