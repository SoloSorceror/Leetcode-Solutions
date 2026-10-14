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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int sz = q.size();
            vector<int> level;

            while(sz--){
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            if(!leftToRight){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};