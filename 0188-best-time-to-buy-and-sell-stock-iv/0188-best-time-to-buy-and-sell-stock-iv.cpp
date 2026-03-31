class Solution {
public:
    int f(int i, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cnt == 0) return 0;

        if (dp[i][buy][cnt] != -1) return dp[i][buy][cnt];

        int profit = 0;

        if (buy) {
            int take = -prices[i] + f(i + 1, 0, cnt, prices, dp);
            int nottake = f(i + 1, 1, cnt, prices, dp);
            profit = max(take, nottake);
        } 
        else {
            int sell = prices[i] + f(i + 1, 1, cnt - 1, prices, dp);
            int notsell = f(i + 1, 0, cnt, prices, dp);
            profit = max(sell, notsell);
        }

        return dp[i][buy][cnt] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return f(0, 1, k, prices, dp);
    }
};