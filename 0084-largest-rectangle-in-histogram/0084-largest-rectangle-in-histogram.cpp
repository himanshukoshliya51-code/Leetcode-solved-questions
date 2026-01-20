class Solution {
public:
 vector<int> findNSE(vector<int>& nums){
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i] = !st.empty()? st.top() : n;

            st.push(i);
        }
        return ans;
    }
    vector<int> findPSSE(vector<int>& nums){
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i =0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i] = !st.empty()? st.top() : -1;

            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
          vector<int> nse =  findNSE(heights);
        vector<int> psee = findPSSE(heights);
       int area = 0;
        
            int n = heights.size();
            for(int i=0;i<n;i++){
               int area1 = ((nse[i]-i)*heights[i])+((i-psee[i])*heights[i])-heights[i];
                area = max(area,area1);

            }
        return area;
    }
    
};