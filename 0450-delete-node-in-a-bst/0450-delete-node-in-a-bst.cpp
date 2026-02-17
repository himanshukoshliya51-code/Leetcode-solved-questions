class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // 🔥 Node found

            // If no left child → return right
            if (!root->left)
                return root->right;

            // If no right child → return left
            if (!root->right)
                return root->left;

            // 🔥 If both children exist
            TreeNode* temp = root->right;

            // Find smallest in right subtree
            while (temp->left)
                temp = temp->left;

            root->val = temp->val;   // Replace value
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
