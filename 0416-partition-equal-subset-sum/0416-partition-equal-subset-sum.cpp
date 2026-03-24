class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int index = 1; index < n; index++){
            for(int k = 1; k <= target; k++){
                bool nonpick = dp[index - 1][k];
                bool pick = false;

                if(k >= nums[index]){   // ✅ FIXED
                    pick = dp[index - 1][k - nums[index]];
                }

                dp[index][k] = pick | nonpick;  // ✅ ALWAYS assign
            }
        }

        return dp[n - 1][target];
    }
};