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
    int rec(TreeNode* root, int &k){
        if(!root) return -1;
        
        int left = rec(root->left,k);
        if (left != -1) return left;   // found in left subtree

        k--;
        if (k==0) return root->val;

        return rec(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = rec(root,k);
        return ans;
    }
};

