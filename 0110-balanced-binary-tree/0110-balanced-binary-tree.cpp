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
    int max_diff= INT_MIN;
    int f(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        max_diff = max(max_diff, abs(lh - rh));
        // cout << root->val << ' ' << lh << ' ' << rh << ' ' << max_diff << endl;
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        f(root);
        return max_diff <= 1;
    }
};