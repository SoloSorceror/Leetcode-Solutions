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
    int rec(TreeNode* root, int parent, int &maxi){
        if(!root) return 0;

        int left = rec(root->left,root->val, maxi);
        int right = rec(root->right,root->val, maxi);

        maxi = max(maxi, left + right);
        return root->val == parent ? max(left,right) + 1 : 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int maxi = 0;
        rec(root,-1,maxi);
        return maxi;
    }
};