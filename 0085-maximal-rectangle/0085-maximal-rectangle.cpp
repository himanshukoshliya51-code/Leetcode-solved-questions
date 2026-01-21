class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int largestArea = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int ind = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                largestArea = max(largestArea, heights[ind] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int ind = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            largestArea = max(largestArea, heights[ind] * (nse - pse - 1));
        }

        return largestArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }

        return maxArea;
    }
};
