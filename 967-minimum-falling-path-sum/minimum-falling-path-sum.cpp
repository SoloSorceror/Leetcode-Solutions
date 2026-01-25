class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));

        for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                //left up
                int left = (j>0) ? dp[i-1][j-1]: INT_MAX;
                // exactly up
                int up = dp[i-1][j];

                // right up
                int right = (j < n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({left,right,up});
            }
        }
        int mini = dp[n-1][0];
        for(int i=1; i<m; i++){
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};