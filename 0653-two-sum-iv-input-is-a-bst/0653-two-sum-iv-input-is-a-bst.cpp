class Solution {
public:
    bool solve(TreeNode* root, int k, unordered_set<int>& s) {
        if(root == NULL) return false;
        
        if(s.count(k - root->val)) return true;
        
        s.insert(root->val);
        
        return solve(root->left, k, s) || 
               solve(root->right, k, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return solve(root, k, s);
    }
};
