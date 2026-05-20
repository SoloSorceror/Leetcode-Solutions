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
        vector<int> prev(m,0);
        vector<int> curr(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else if(i==0 && j>0){
                    curr[j] = grid[i][j] + curr[j-1];
                }
                else if(j==0 && i>0){
                    curr[j] = grid[i][j] + prev[j];
                }
                else curr[j] =  grid[i][j] + min(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[m-1];
    }
};