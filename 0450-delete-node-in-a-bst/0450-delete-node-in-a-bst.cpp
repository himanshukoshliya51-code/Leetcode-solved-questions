class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        TreeNode* parent = NULL;
        TreeNode* node = root;

       
        while (node && node->val != key) {
            parent = node;
            if (key < node->val)
                node = node->left;
            else
                node = node->right;
        }

        if (!node) return root;  // not found

        // Case 1 & 2: Node has 0 or 1 child
        if (!node->left || !node->right) {
            TreeNode* child = node->left ? node->left : node->right;

            if (!parent) {  // deleting root
                delete node;
                return child;
            }

            if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;

            delete node;
        }
        else {
            // 🔥 Case 3: Two children
            TreeNode* successorParent = node;
            TreeNode* successor = node->right;

            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            node->val = successor->val;

            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            delete successor;
        }

        return root;
    }
};
