class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        rec(n,curr,0,0,ans);
        return ans;
    }

private:
    void rec(int n, string &curr, int openCount, int closeCount, vector<string> &ans){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(openCount < n){
            curr.push_back('(');
            rec(n,curr,openCount+1,closeCount,ans);
            curr.pop_back();
        }
        if (closeCount < openCount){
            curr.push_back(')');
            rec(n,curr,openCount,closeCount+1,ans);
            curr.pop_back();
        }
    }
};