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
    int f(TreeNode* root, int max_till_now) {
        if(root == NULL) return 0;

        int count = 0;
        if(root->val >= max_till_now) {
            count = 1;
            max_till_now = root->val;
        }
        count += f(root->left, max_till_now);
        count += f(root->right, max_till_now);
        return count;
    }
    int goodNodes(TreeNode* root) {

        return f(root, INT_MIN);
    }
};
