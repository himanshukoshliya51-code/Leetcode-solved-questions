class Solution {
public:

    void helper(vector<string>&s , string cur , int n , int open , int close){
       
        if(open == close && close == n){
            s.push_back(cur);
            return;
        }

        if(open>close){
            helper(s,cur + ")",n,open , close+1);
        }

         if(open<n){
            helper(s,cur + "(",n,open+1 , close);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        int open = 0;
        int close = 0;
        helper(s,"",n,open , close);
        return s;
    }
};