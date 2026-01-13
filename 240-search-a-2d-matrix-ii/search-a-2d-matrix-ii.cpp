class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row <n && col>=0){
            int ans = matrix[row][col];

            if(ans<target){
                row++;
            }
            else if(ans>target){
                col--;
            }
            else if(ans == target){
                return true;
            }
        }
        return false;
    }
};