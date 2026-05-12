class Solution {
public:
    void rec(int open, int close, int n, string str, vector<string> &ans){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            rec(open+1,close,n,str,ans);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            rec(open,close+1,n,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        int open = 0, close = 0;
        vector<string> ans;
        rec(open,close,n,str,ans);
        return ans;
    }
};