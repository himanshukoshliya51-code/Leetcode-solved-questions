class Solution {
public:
    int f(int node, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if (node == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9; 
        }

        if(dp[node][amount] != -1){
            return dp[node][amount];
        }

        int nonpick = f(node - 1, amount, coins,dp);

        int pick = 1e9;
        if (coins[node] <= amount) {
            pick = 1 + f(node, amount - coins[node], coins,dp); 
        }

        return dp[node][amount] = min(pick, nonpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n - 1, amount, coins,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};