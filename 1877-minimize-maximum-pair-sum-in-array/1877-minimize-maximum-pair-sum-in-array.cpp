class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // int max = INT_MIN;
        // int min = INT_MAX;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>max) max = nums[i];
        //     if(nums[i]<min) min = nums[i];
        // }
        // return max + min;

        int ans = INT_MIN;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            int sum = nums[i]+nums[n-i-1];
            ans= max(ans,sum);
        }
        return ans;
    }
};