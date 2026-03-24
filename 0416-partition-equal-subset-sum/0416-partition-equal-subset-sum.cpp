class Solution {
public:

bool f(int index , int target , vector<int>& nums, vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }
    if(index == 0){ 
        return nums[0]==target;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    bool nonpick = f(index-1,target,nums,dp);

    bool pick = false;
    if(target >= nums[index]){
        pick = f(index-1,target-nums[index],nums,dp);
    }

    return dp[index][target] = nonpick | pick ;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(sum%2 == 1){
            return false;
        }
        return f(n-1,target,nums,dp);
        
    }
};