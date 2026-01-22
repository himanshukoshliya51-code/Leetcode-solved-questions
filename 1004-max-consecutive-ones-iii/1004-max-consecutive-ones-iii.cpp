class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zeros = 0;
        int maxl = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeros++;

            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            maxl = max(maxl, r - l + 1);
        }

        return maxl;
    }
};
