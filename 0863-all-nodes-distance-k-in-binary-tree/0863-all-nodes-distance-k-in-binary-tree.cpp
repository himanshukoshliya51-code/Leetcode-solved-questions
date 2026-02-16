/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 void storeParent(TreeNode* root, 
                      unordered_map<TreeNode*, TreeNode*>& parent,
                      TreeNode* target) {
        
        queue<TreeNode*> q;
        q.push(root);
        // parent[root] = NULL;

        // TreeNode* targetNode = NULL;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // if(curr->val == target)
            //     targetNode = curr;

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        storeParent(root,parent,target);

        queue<TreeNode*>qu;
        unordered_map<TreeNode*,bool>visited;

        qu.push(target);
        visited[target]=true;
        int curr_level = 0;
        while(!qu.empty()){
            int size = qu.size();
            if(curr_level==k)break;
            curr_level++;

            for(int i=0;i<size;i++){
                TreeNode* current = qu.front();
                qu.pop();
                if(current->left && !visited[current->left]){
                        qu.push(current->left);
                        visited[current->left] = true;
                }
                 if(current->right && !visited[current->right]){
                        qu.push(current->right);
                        visited[current->right] = true;
                }
                 if(parent[current] && !visited[parent[current]]){
                        qu.push(parent[current]);
                        visited[parent[current]] = true;
                }
            }

        }

        vector<int>result;
        while(!qu.empty()){
                TreeNode*current = qu.front();
                qu.pop();
                result.push_back(current->val);
        }

        return result;
        

        
    }
};