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

    vector<int> findNHE(vector<int>& nums){
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i] = !st.empty()? st.top() : n;

            st.push(i);
        }
        return ans;
    }
    vector<int> findPHHE(vector<int>& nums){
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i =0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i] = !st.empty()? st.top() : -1;

            st.push(i);
        }
        return ans;
    }


    long long subArrayRanges(vector<int>& arr) {
         vector<int> nse =  findNSE(arr);
        vector<int> psee = findPSSE(arr);
        vector<int> nhe = findNHE(arr);
        vector<int> phhe = findPHHE(arr);
        
            int n = arr.size();
        
        long long sum = 0;
        long long sum1 = 0;
        long long sum2 = 0;

        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            long long lefts = i - psee[i];  
            long long rights = nse[i] - i;

            long long lefth = i - phhe[i];  
            long long righth = nhe[i] - i;
            

            long long freq1 = lefts*rights*1LL;
            long long val1 = (freq1*arr[i]*1LL) ; 
            sum1 = (sum1 + val1);

             long long freq2 = lefth*righth*1LL;
            long long val2 = (freq2*arr[i]*1LL) ; 
            sum2 = (sum2 + val2) ;
        }
        sum = sum2-sum1;
        
        return sum;
        
    }
};