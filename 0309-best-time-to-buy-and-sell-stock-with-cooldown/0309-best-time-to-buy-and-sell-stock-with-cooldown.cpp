class Solution {
public:
int f(int i , int buy , vector<int>& prices , vector<vector<int>>& dp){
    if(i == prices.size() )return 0;
    int profit = 0;

    if(dp[i][buy] != -1)return dp[i][buy];

    if(buy==1){ 
        int take  = -prices[i]+f(i+1,0,prices,dp);
        int nottake = f(i+1,1,prices,dp);
         profit = max(take,nottake);
    }
    else if(buy == 0){
        profit = max(prices[i]+f(i+1,2,prices,dp),f(i+1, 0 ,prices, dp));

    }
    if(buy == 2){
       profit =  f(i+1,1,prices,dp);
    }

    return dp[i][buy] = profit;
}
    int maxProfit(vector<int>& prices) {
          int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f(0,1,prices,dp);
        
    }
};