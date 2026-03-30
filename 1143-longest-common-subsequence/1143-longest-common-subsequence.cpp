class Solution {
public:
int f(int n ,int m , string &word1 , string &word2 , vector<vector<int>>& dp){
if(n<0 || m<0)return 0;

if(dp[n][m] != -1)return dp[n][m];
if(word1[n] == word2[m]){
    return dp[n][m] = 1+f(n-1,m-1,word1,word2,dp);
}
else{
    return dp[n][m] =  max(f(n,m-1,word1,word2,dp),f(n-1,m,word1,word2,dp));
}
}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1, m-1 , text1 , text2 ,dp);
    }
};