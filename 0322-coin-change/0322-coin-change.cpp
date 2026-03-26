class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i = 0;i<=amount;i++){
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
                else
            dp[0][i] =  1e9; 
        }
        for(int i=1;i<n;i++){
            for(int amnt=0;amnt<=amount;amnt++){
                 int nonpick = dp[i - 1][amnt];

        int pick = 1e9;
        if (coins[i] <= amnt) {
            pick = 1 + dp[i][amnt - coins[i]];
        }
        dp[i][amnt] = min(pick,nonpick);

            }

        }
        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};