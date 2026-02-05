class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int newIndex = (i+nums[i])%n;
                result[i]=nums[newIndex];
            }
            else if(nums[i]<0){
                result[i]=nums[(n+i-abs(nums[i])%n)%n];
            }
            else{
                result[i]=nums[i];
            }
        }
        return result;
    }
};