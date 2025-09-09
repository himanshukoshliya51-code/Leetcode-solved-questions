class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(0, nums, current, res);
        return res;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(current); // add current subset
            return;
        }

        // Choice 1: include nums[index]
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, res);

        // Choice 2: exclude nums[index] (backtrack)
        current.pop_back();
        backtrack(index + 1, nums, current, res);
    }
};
