class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m,0);
        vector<int> curr(m,0);

        for(int i=0; i<m; i++){
            prev[i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                //left
                int left = (j>0) ? prev[j-1]: INT_MAX;
                // exactly up
                int up = prev[j];

                // right up
                int right = (j < n-1) ? prev[j+1] : INT_MAX;

                curr[j] = matrix[i][j] + min({left,right,up});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};