class Solution {
public:
    int f(int i, int target, vector<int>& nums, vector<vector<int>>& dp, int offset) {

        // ❗ boundary check (fixes runtime error)
        if (target + offset < 0 || target + offset >= 2 * offset + 1)
            return 0;

        if (i == 0) {
            int count = 0;
            if (target == nums[0]) count++;
            if (target == -nums[0]) count++;
            return count;
        }

        if (dp[i][target + offset] != -1)
            return dp[i][target + offset];

        int plus = f(i - 1, target - nums[i], nums, dp, offset);
        int minus = f(i - 1, target + nums[i], nums, dp, offset);

        return dp[i][target + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) sum += x;

        // ❗ important check
        if (abs(target) > sum) return 0;

        int offset = sum;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return f(n - 1, target, nums, dp, offset);
    }
};