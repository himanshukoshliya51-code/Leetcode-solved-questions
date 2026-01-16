class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        unordered_map<int,int> mp;

        // Build next greater for nums2
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            mp[nums2[i]] = ans[i];
            st.push(nums2[i]);
        }

        // Build result in nums1 order
        vector<int> ansf;
        for(int x : nums1) {
            ansf.push_back(mp[x]);
        }

        return ansf;
    }
};
