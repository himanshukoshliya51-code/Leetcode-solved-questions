class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Backtracking function
    void backtrack(int start, string& s, vector<string>& current, vector<vector<string>>& result) {
        // Base case: reached the end
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        // Explore all possible substrings starting at 'start'
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                // Choose
                current.push_back(s.substr(start, end - start + 1));
                // Explore
                backtrack(end + 1, s, current, result);
                // Unchoose (backtrack)
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, s, current, result);
        return result;
    }
};