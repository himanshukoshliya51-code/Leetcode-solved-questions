class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&k>0 && (st.top()-'0'>(num[i]-'0'))){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        while(res.size() > 0 && 
              res.back() == '0') {

            res.pop_back();
        }
        
        // Reverse to get the actual number
        reverse(res.begin(), res.end());
        
        // Edge case
        if(res.empty()) return "0";
        
        // Return the stored result
        return res;
        
    }
};