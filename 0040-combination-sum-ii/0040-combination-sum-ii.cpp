class Solution {
public:
    void outputvalue(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& between, int index) {
        if (target == 0) {
            ans.push_back(between);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break; // no need to continue further (since sorted)

            between.push_back(candidates[i]);
            outputvalue(candidates, target - candidates[i], ans, between, i + 1);
            between.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> between;

        sort(candidates.begin(), candidates.end()); // sort first to handle duplicates

        outputvalue(candidates, target, ans, between, 0);

        return ans;
    }
};
