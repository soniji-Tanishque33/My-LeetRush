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
    int maxdiff = INT_MIN;
    int f(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = 1+f(root->left);
        int rh = 1+f(root->right);
        maxdiff =  max(maxdiff, abs(rh-lh));

        return max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        f(root);
        return maxdiff <= 1;
    }
};