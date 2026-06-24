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
    int maxSum = INT_MIN;

    int dfs(TreeNode* root){
        if(!root) return 0;

        int rootVal = root->val;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int ans_down = left + right + rootVal;
        int one_best = max(left , right) + rootVal;
        int only_root = rootVal;

        maxSum = max({maxSum , ans_down , one_best , only_root});

        return max(one_best , only_root);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        dfs(root);
        
        return maxSum;
    }
};
