class Solution {
public:
    int rec(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size(); 

        if(i<0 || i>=n || j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;

        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;

        for(int djx=-1; djx<=1; djx++){
            for(int djy=-1; djy<=1; djy++){
                int cherries = 0;
                if(j1==j2){
                    cherries = grid[i][j1];
                }
                else{
                    cherries = grid[i][j1] + grid[i][j2];
                }
                cherries += rec(i+1,j1+djx,j2+djy,grid,dp);
                maxi = max(maxi,cherries);
            }
        }
        return dp[i][j1][j2] = maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return rec(0,0,m-1,grid,dp);
    }
};