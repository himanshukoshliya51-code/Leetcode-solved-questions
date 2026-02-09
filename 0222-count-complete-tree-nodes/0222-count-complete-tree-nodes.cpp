class Solution {
public:
    int counting(TreeNode* root) {
        if (root == NULL) return 0;

        int leftCount = counting(root->left);
        int rightCount = counting(root->right);

        return 1 + leftCount + rightCount;
    }

    int countNodes(TreeNode* root) {
        return counting(root);
    }
};
