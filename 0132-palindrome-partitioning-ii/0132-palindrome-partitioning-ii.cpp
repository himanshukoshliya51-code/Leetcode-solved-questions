class Solution {
public:

bool ispalind(int i, int j, string& s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int minCut(string s) {
        int n = s.size();
       vector<int>dp(n+1,0);

       for(int i = n-1;i>=0;i--){
        int mini = INT_MAX;
    for(int j = i;j<n;j++){
        if(ispalind(i,j,s)){
        int cuts = 1+ dp[j+1];
         mini = min(mini,cuts);
        }
    }
    dp[i] = mini;
       }
        return dp[0]-1;
    }
};