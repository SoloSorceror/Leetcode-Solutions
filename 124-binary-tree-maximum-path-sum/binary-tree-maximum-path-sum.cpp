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
    int dfs(TreeNode* root, int &sum){
        if(!root) return 0;
        int left = max(0,dfs(root->left,sum));
        int right = max(0,dfs(root->right,sum));

        int curr = root->val + left + right;
        sum = max(sum, curr);
        return root->val + max(0,max(left,right));
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root,sum);
        return sum;
    }
};