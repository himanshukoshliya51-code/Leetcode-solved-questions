class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(half + 1), right(half + 1);

        // LEFT HALF
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }
            left[cnt].push_back(sum);
        }

        // RIGHT HALF
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i + half];
                    cnt++;
                }
            }
            right[cnt].push_back(sum);
        }

        // Sort right half for binary search
        for (int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Combine both halves
        for (int lcnt = 0; lcnt <= half; lcnt++) {
            for (int lsum : left[lcnt]) {

                int rcnt = half - lcnt;
                int target = totalSum / 2 - lsum;

                auto &vec = right[rcnt];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = lsum + *it;
                    ans = min(ans, abs(totalSum - 2 * sum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sum = lsum + *it;
                    ans = min(ans, abs(totalSum - 2 * sum));
                }
            }
        }

        return ans;
    }
};