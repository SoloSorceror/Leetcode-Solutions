/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int& count) {
        if (!root)
            return 0;

        int lefty = helper(root->left,count);
        int righty = helper(root->right,count);

        if (lefty == -1 || righty == -1) {
            count++;
            return 1;
        } 
        if (lefty == 1 || righty == 1) {
            return 0;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        if (helper(root, count) == -1) {
            count++;
        }
        return count;
    }
};