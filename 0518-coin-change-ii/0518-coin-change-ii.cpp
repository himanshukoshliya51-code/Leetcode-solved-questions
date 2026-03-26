class Solution {
public:
 int f(int node, int amount, vector<int>& coins,vector<vector<int>>& dp) {
    if(amount == 0){
        return 1;
    }
        if (node == 0) {
            if (amount % coins[0] == 0)
                return 1;
            return 0; 
        }

        if(dp[node][amount] != -1){
            return dp[node][amount];
        }

        int nonpick = f(node - 1, amount, coins,dp);

        int pick = 0;
        if (coins[node] <= amount) {
            pick = f(node, amount - coins[node], coins,dp); 
        }

        return dp[node][amount] = (pick + nonpick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n - 1, amount, coins,dp);
        return ans;
    }
};