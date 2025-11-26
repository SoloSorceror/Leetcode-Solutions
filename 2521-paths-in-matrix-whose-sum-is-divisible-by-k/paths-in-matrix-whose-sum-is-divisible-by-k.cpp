class Solution {
public:
    static const int MOD = 1e9 + 7;
    int rec(int i, int j, int sum, vector<vector<int>> &grid, int k,vector<vector<vector<int>>>& dp){
        if(i == 0 && j == 0){
            int total = (sum + grid[0][0]) % k;
            return (total == 0) ? 1 : 0;
        }

        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        long long ways = 0;
        int newSum = (sum + grid[i][j]) % k;

        if (i > 0)
            ways = (ways + rec(i - 1, j, newSum, grid, k, dp)) % MOD;
        if (j > 0)
            ways = (ways + rec(i, j - 1, newSum, grid, k, dp)) % MOD;

        dp[i][j][sum] = (int)(ways % MOD);
        return dp[i][j][sum];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int i = grid.size();
        int j = grid[0].size();

        vector<vector<vector<int>>> dp(i,vector<vector<int>>(j,vector<int>(k,-1)));
        return rec(i-1,j-1,0,grid,k,dp);
    }
};