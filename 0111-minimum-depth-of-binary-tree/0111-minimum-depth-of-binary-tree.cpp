class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        // If left subtree is NULL
        if(root->left == NULL)
            return 1 + minDepth(root->right);

        // If right subtree is NULL
        if(root->right == NULL)
            return 1 + minDepth(root->left);

        // If both children exist
        return 1 + min(minDepth(root->left), 
                       minDepth(root->right));
    }
};