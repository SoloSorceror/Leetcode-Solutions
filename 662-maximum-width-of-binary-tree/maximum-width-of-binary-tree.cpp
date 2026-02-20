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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long maxi = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            long long minIndex = q.front().second;
            long long left,right;

            for(int i=0; i<sz;i++){
                auto [node,index] = q.front();
                q.pop();
                long long currI = index - minIndex; 
                if(i==0) left = currI;
                if(i==sz-1) right = currI;

                if(node->left){
                    q.push({node->left,2*currI+1});
                }
                if(node->right) q.push({node->right, 2*currI+2});
            }
            maxi = max(maxi, right - left+1);
        }
        return maxi;
    }
};
