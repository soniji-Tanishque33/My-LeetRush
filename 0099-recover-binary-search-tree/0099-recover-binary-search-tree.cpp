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
    void get_nodes(TreeNode* root, vector<TreeNode*>& nodes) {
        if(root == NULL) return;
        get_nodes(root->left, nodes);
        nodes.push_back(root);
        get_nodes(root->right, nodes);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        get_nodes(root, nodes);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i = 0; i+1<nodes.size(); i++) {
            if(nodes[i]->val > nodes[i+1]->val) {
                if(!first) first = nodes[i];
                second = nodes[i+1];
            }
        }

        if(first && second) swap(first->val, second->val);



    }
};