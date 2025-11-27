/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);

        vector<string> ans;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                ans.push_back(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            } else
                ans.push_back("null");
        }
        while (!ans.empty() && ans.back() == "null") {
            ans.pop_back();
        }
        string s = "";
        for (int i = 0; i < ans.size(); i++) {
            s.append(ans[i]);
            if (i + 1 < ans.size())
                s.push_back(',');
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size() == 0) return nullptr;

        vector<string> tokens;
        string temp ="";

        for(char c :data){
            if(c==','){
                tokens.push_back(temp);
                temp.clear();
            }else{
                temp.push_back(c);
            }
        }
        if (!temp.empty()) tokens.push_back(temp);

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i =1;
        while(!q.empty() && i< tokens.size()){
            TreeNode* curr = q.front();
            q.pop();

            if(tokens[i] != "null"){
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            if(i>= tokens.size()) break;

            if(tokens[i] != "null"){
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));