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
        int n = s.length();
        int prev1 = 1;
        int prev2 = 1;

        for(int i=n-1; i>=0; i--){
            int curr = 0;
            if(s[i] == '0'){
                prev2 = prev1;
                prev1 = 0;
                continue;
            }
            curr = prev1;
            if(i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};