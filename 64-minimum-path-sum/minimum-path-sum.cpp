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
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        dp[0][0] = grid[0][0];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) continue;
                if(i==0 && j>0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
                else if(j==0 && i>0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                else dp[i][j] =  grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};