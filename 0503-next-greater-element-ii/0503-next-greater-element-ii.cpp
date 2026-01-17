class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        for (int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

           
                ans[idx] = st.empty() ? -1 : nums[st.top()];
            

            st.push(idx);
        }
        return ans;
    }
};
