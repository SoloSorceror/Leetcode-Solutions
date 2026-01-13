class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> marked(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    marked[i][j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(marked[i][j] == 1){
                    for(int p =0; p<m; p++){
                        matrix[i][p] = 0;
                    }
                    for(int k=0; k<n; k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};