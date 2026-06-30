class Solution {
private:
    int chomp(int i, string &s, vector<int> &memo){
        if(i==s.length()) return 1;

        if(s[i] == '0') return 0;

        if(memo[i] != -1) return memo[i];

        int count = chomp(i+1,s,memo);

        if(i+1 < s.length() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
            count += chomp(i+2,s,memo);
        }
        return memo[i] = count;
    }

public:
    int numDecodings(string s) {
        vector<int> memo(s.length(),-1);
        return chomp(0,s,memo);
    }
};