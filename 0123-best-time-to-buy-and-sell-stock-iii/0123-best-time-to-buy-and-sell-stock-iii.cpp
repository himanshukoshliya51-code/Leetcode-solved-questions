class Solution {
public:
  int f(int i , int buy ,int cnt , vector<int>& prices , vector<vector<vector<int>>>& dp){
    if(cnt == 0)return 0;
    if(i == prices.size() )return 0;
    int profit = 0;

    if(dp[i][buy][cnt] != -1)return dp[i][buy][cnt];

    if(buy){
        int take = 0;
       
         take  = -prices[i]+f(i+1,0,cnt,prices,dp);
    
        int nottake = f(i+1,1,cnt,prices,dp);
         profit = max(take,nottake);
        
    }
    else{
        profit = max(prices[i]+f(i+1,1,cnt-1,prices,dp),f(i+1, 0 ,cnt ,prices, dp));

    }

    return dp[i][buy][cnt] = profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));        return f(0,1,2,prices,dp);
        
    }
};