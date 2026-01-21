class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int temp=-1;
            if(nums[i]&1){
                temp=nums[i]^1;
                int x1=1;
                int j=1;
                while((nums[i]>>j)&1){
                    j++;
                    x1=x1<<1;
                }
                int x2=nums[i]-x1;
                if(x2^x1==nums[i]){
                    temp=min(temp,x2);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};