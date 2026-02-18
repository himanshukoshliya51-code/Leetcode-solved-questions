class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if(preorder.size() == 0) return NULL;

        // Create root
        TreeNode* root = new TreeNode(preorder[0]);

        // Find division point
        int i = 1;
        while(i < preorder.size() && preorder[i] < root->val) {
            i++;
        }

        // Create left and right subarrays
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + i);
        vector<int> rightPre(preorder.begin() + i, preorder.end());

        // Recursive calls
        root->left = bstFromPreorder(leftPre);
        root->right = bstFromPreorder(rightPre);

        return root;
    }
};
