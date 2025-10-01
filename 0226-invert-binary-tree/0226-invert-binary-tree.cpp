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
    TreeNode *method2(TreeNode * root) {
        if(root == NULL) return NULL;
        // we will make a stack to check ifwe have traversed the full tree or not
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if(curr == NULL) continue;
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left, curr->right);

        }
        return root;
    }
    TreeNode* method1(TreeNode * root ) {
        if(root == NULL) {
            return nullptr;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        method1(root->left);
        method1(root->right);
        return root;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        return method2(root);
    }
};