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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            for(int i = 0; i<s; i++) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left) {
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if(top->right) {
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }

        vector<int> visited(501, 0);

        queue<TreeNode*> que;
        que.push(target);

        while(k-- && !que.empty()) {
            int s = que.size();
            for(int i = 0; i<s; i++) {
                
                TreeNode* top = que.front(); que.pop();
                visited[top->val] = 1;

                if(top->left && visited[top->left->val] == 0) {
                    que.push(top->left);
                }

                if(top->right && visited[top->right->val] == 0) {
                    que.push(top->right);
                }

                if(parent[top->val] && visited[parent[top->val] -> val] == 0) {
                    que.push(parent[top->val]);
                }
            }
        }

        vector<int> ans;
        while(!que.empty()) {
            ans.push_back(que.front()->val);
            que.pop();
        }
        return ans;
    }
};