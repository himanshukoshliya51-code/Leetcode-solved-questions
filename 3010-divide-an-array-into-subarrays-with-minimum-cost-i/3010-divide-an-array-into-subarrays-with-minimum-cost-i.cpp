class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index = -1;
        for(int i=1;i<n;i++){
            if(nums[i]<min1) {
                min1 = nums[i];
                index = i;
                }
        }
         for(int i=1;i<n;i++){
            if(nums[i]<min2 && i!=index) {
                min2 = nums[i];       
                }
        }

        int ans = nums[0]+min1+min2;
        return ans;
        
    }
};