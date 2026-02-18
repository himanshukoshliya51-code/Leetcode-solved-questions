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
        void inorder(TreeNode* root ){
            if(root == NULL)return;
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
               void compare(TreeNode* root,vector<int>two){
                if(root == NULL)return;
                if(root->val == two[0] ){
                    root->val = two[1];
                }
                else if(root->val == two[1]){
                    root->val = two[0];
                }
                compare(root->left,two);
                compare(root->right,two);

               }

vector<int>ans;
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int>two;
        vector<int>sorted = ans ;
        for(int i=0;i<ans.size();i++){
            sorted[i]=ans[i];
        }
        sort(sorted.begin(),sorted.end());

        for(int i=0;i<ans.size();i++){
            if(ans[i] != sorted[i]){
                two.push_back(ans[i]);
                two.push_back(sorted[i]);
                break;
            }
        }

        compare(root,two);

        return ;
    }
};