class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n= nums.size();
         sort(nums.begin(),nums.end());
         int r =0;
         int l =0;
         int ans = INT_MAX;
         if(k==1){
            return 0;
         }
       
       
    
            while(r<n-k+1){
                ans = min (ans,nums[r+k-1]-nums[r]);
                r++;
              
        
        }
        return ans;
        
    }
};