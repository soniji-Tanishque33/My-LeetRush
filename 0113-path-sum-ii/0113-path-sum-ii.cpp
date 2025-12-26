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
    void dfs(TreeNode* root, int target, vector<int> path, vector<vector<int>>& ans ) {
        if(root == NULL) return ;

        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && target == root->val) {
            ans.push_back(path);
        }

        dfs(root->left, target-root->val, path, ans);
        dfs(root->right, target-root->val, path, ans);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        dfs(root, targetSum, {}, ans);
        return ans;
    }
};

/*

f(5, 22, {}, {}) -> f(4, 17, {5}, {}) -> f(11, 13, {5,4}, {}) -> f(7, 2, {5, 4, 11}, {}) ->f(null) 
       |                    |                     |                        |
                        f(null)         f(2, 2, {5,4, 11, 2}, {{5, 4, 11, 2}})            f(null)
                                                |
                                        f(null)         f(null)



*/                      