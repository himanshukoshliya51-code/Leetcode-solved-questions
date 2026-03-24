class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1) return false;

        int target = sum / 2;

        vector<bool>prev(target+1,0),curr(target+1,0);

        prev[0]=curr[0]=true;

      if(nums[0] <= target)  
            prev[nums[0]] = true;


        for(int index = 1; index < n; index++){
            for(int k = 1; k <= target; k++){
                bool nonpick = prev[k];
                bool pick = false;

                if(k >= nums[index]){   
                    pick = prev[k - nums[index]];
                }

                curr[k] = pick | nonpick; 
            }
            prev = curr;
        }

        return prev[target];
    }
};