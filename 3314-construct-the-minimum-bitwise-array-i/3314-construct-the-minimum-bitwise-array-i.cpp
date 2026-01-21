class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0){
                ans[i]=-1;
            }
            else{
                ans[i]=INT_MAX;
                for(int j=0;j<nums[i];j++){
                    if((j|(j+1)) == nums[i]){
                        if(j<ans[i]) ans[i]=j;
                    }
                }
               
            
             if(ans[i] == INT_MAX) {
                    ans[i] = -1;
                }
            }


        }
        return ans;
        
    }
};