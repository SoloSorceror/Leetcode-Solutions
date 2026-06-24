class Solution {
public:

    int counter(int val, vector<vector<int>>& matrix){
        int n = matrix.size();

        int row = n-1, col = 0;
        int count = 0;

        while(row>=0 && col<n){
            if(matrix[row][col] <= val){
                count += (row + 1);
                col++;
            }else{
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int left = matrix[0][0];
        int right = matrix[n-1][n-1];

        while(left<right){
            int mid = left + (right-left)/2;
            int count = counter(mid,matrix);
            if(count < k){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};