class Solution {
public:
    void rec(int idx, string curr, vector<string> &ans, string digits,unordered_map<char,string> &mp){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        string str = mp[digits[idx]];

        for(char c: str){
            curr.push_back(c);
            rec(idx+1,curr,ans,digits,mp);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        rec(0,"",ans,digits,mp);
        return ans;
    }
};