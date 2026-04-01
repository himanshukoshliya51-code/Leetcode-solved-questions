class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
    int longestStrChain(vector<string>& words) {
         int n = words.size();
           sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        vector<int>dp(n,1),hash(n);

        int maxi = 1;
        int lastIndex =0;

        for(int i =0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(words[i].size() == words[prev].size() + 1 &&longestCommonSubsequence(words[i],words[prev]) == words[prev].size() && dp[prev]+1 > dp[i]){
                    dp[i] = 1+ dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
return maxi;
    }
};