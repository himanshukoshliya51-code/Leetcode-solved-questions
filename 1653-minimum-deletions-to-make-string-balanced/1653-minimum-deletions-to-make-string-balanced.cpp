class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;   // number of 'b' before current index
        int ans = 0;      // minimum deletions so far

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { // c == 'a'
                ans = min(ans + 1, bCount);
            }
        }

        return ans;
    }
};
