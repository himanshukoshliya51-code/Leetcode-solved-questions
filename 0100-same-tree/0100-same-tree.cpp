class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both are NULL
        if (p == NULL && q == NULL) return true;

        // Case 2: one is NULL
        if (p == NULL || q == NULL) return false;

        // Case 3: values differ
        if (p->val != q->val) return false;

        // Case 4: check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
