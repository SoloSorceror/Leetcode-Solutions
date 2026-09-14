
class Solution {
public:
    int rec(int m, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(m == triangle.size() - 1)
            return triangle[m][n];

        if(dp[m][n] != 1e9)
            return dp[m][n];

        int down = rec(m+1, n, triangle, dp);
        int diag = rec(m+1, n+1, triangle, dp);

        return dp[m][n] = triangle[m][n] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        return rec(0, 0, triangle, dp);
    }
};
