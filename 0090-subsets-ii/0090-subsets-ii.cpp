class Solution {
public:

void finalOP(vector<int>&ds,vector<vector<int>>&ans, vector<int>&nums,int ind){
    ans.push_back(ds);

    for(int i = ind;i<nums.size();i++){
if(i!=ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        finalOP(ds,ans, nums, i+1);
        ds.pop_back();
    }
}



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        finalOP(ds, ans, nums, 0);
        return ans;          
    }
};