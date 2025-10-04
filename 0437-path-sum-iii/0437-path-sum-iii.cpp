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

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        return dfs(root, 0, targetSum, prefix);
    }

    int dfs(TreeNode* root, long long currsum, int target, unordered_map<long long, int>& prefix) {
        if(root == NULL) return 0;

        int count = 0;

        currsum += root->val;
        if(prefix.find(currsum-target) != prefix.end()) {
            count += prefix[currsum-target];
        }

        prefix[currsum]++;
        count += dfs(root->left, currsum, target, prefix);
        count += dfs(root->right, currsum, target, prefix);

        prefix[currsum]--;
        return count;
    }
};