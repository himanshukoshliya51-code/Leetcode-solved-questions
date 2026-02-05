class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int newIndex;

            if (nums[i] > 0) {
                newIndex = (i + nums[i]) % n;
            }
            else if (nums[i] < 0) {
                newIndex = (n + i - (abs(nums[i]) % n)) % n;
            }
            else {
                newIndex = i;
            }

            result[i] = nums[newIndex];
        }

        return result;
    }
};
