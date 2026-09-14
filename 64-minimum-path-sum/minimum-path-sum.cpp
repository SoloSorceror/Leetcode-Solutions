class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j< 0) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(rec(i-1,j,grid,dp), rec(i,j-1,grid,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m+1,1e9);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 && j==1) dp[1] = grid[0][0]; 
                else dp[j] = grid[i-1][j-1] + min(dp[j-1], dp[j]);
            }
        }

        return dp[m];
    }
};