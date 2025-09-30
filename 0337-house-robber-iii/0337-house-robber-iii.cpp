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
    int f(TreeNode* root, bool par_robbed, unordered_map<TreeNode*, vector<int>>& dp) {
        if(root == NULL) return 0;
        if(dp.find(root) == dp.end()) {
            dp[root] = vector<int>(2, -1);
        }
        if(dp[root][par_robbed] != -1) return dp[root][par_robbed];
        
        int rob = f(root->left, 1, dp) + f(root->right, 1, dp) + root->val;
        int no_rob = f(root->left, 0, dp) + f(root->right, 0, dp);

        if(par_robbed == true) return dp[root][par_robbed] = no_rob;
        return dp[root][par_robbed] = max(rob, no_rob);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        return f(root, 0, dp);
    }
};