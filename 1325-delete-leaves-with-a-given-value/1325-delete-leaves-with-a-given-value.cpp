class Solution {
public:
    TreeNode* solve(TreeNode* root, int target) {
        if (root == NULL) return NULL;

        root->left = solve(root->left, target);
        root->right = solve(root->right, target);

        if (root->val == target && 
            root->left == NULL && 
            root->right == NULL) {
           // delete root;
            return NULL;
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};
