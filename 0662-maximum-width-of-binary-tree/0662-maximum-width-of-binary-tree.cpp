/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> qu;
        qu.push({root, 0});

        while (!qu.empty()) {
            int size = qu.size();
            long long mmin = qu.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long cur_id = qu.front().second - mmin;
                TreeNode* node = qu.front().first;
                qu.pop();

                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;

                if (node->left)
                    qu.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    qu.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};
