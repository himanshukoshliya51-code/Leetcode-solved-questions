class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* buildBST(vector<int>& ans, int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(ans[mid]);

        root->left = buildBST(ans, left, mid - 1);
        root->right = buildBST(ans, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);               // Step 1: sorted array
        return buildBST(ans, 0, ans.size() - 1); // Step 2: balanced BST
    }
};
