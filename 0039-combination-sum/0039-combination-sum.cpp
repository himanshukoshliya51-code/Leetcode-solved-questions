class Solution {
public:
    void outputvalue(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& between, int index) {
        if (target == 0) {
            ans.push_back(between);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                between.push_back(candidates[i]);
                // recursive call allowing same element again (i not i+1)
                outputvalue(candidates, target - candidates[i], ans, between, i);
                between.pop_back(); // backtrack
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> between;
        outputvalue(candidates, target, ans, between, 0);
        return ans;
    }
};
