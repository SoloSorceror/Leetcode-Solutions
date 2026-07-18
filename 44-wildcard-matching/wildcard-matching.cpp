class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return rec(0,0,s,p,dp);
    }
private:
    bool rec(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        int n = s.size();
        int m = p.size();


        if(i == n && j==m) return dp[i][j] = true;

        if(j==m) return dp[i][j] = false;

        if(i==n){
            while(j<m){
                if(p[j] != '*') return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = rec(i+1, j+1, s, p, dp);

        if(p[j] == '*'){
            return dp[i][j] = rec(i,j+1,s,p, dp) || rec(i+1,j,s,p, dp);
        }
        return dp[i][j] = false;
    }
};