class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        
        // If it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }
        
        // Recur for left and right
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};