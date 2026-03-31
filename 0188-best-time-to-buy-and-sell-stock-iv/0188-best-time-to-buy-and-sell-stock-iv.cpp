class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (k == 0 || n == 0) return 0;

        // Optimization
        // if (k >= n / 2) {
        //     int profit = 0;
        //     for (int i = 1; i < n; i++) {
        //         if (prices[i] > prices[i - 1])
        //             profit += prices[i] - prices[i - 1];
        //     }
        //     return profit;
        // }

        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            // ✅ reset to avoid garbage values
            curr = vector<vector<int>>(2, vector<int>(k + 1, 0));

            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = 1; cnt <= k; cnt++) {

                    if (buy == 1) {
                        int take = -prices[i] + after[0][cnt];
                        int nottake = after[1][cnt];
                        curr[buy][cnt] = max(take, nottake);
                    } 
                    else {
                        int sell = prices[i] + after[1][cnt - 1];
                        int notsell = after[0][cnt];
                        curr[buy][cnt] = max(sell, notsell);
                    }
                }
            }

            after = curr;
        }

        return after[1][k];
    }
};