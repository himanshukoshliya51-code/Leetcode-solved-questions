class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i); 
        }

        int mini = INT_MAX;

        for(auto &it : mp){
            vector<int> &v = it.second;

            if(v.size() < 3) continue;

            for(int i = 0; i + 2 < v.size(); i++){
                int a = v[i];
                int b = v[i+1];
                int c = v[i+2];

                int dist = abs(a-b) + abs(a-c) + abs(b-c);

                mini = min(mini, dist);
            }
        }

        return (mini == INT_MAX ? -1 : mini);
    }
};