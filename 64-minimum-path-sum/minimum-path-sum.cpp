class Solution {
private:
    int rec(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row<0 || col <0) return 1e9;
        if(row == 0 && col ==0) return grid[0][0];
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] =  grid[row][col] + min(rec(row-1,col,grid,dp),rec(row,col-1,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(n-1, m-1, grid,dp);
    }
};