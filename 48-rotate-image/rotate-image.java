class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        int top = 0;
        int bottom = n - 1;
        while (top < bottom) {
            int[] temp = matrix[top];
            matrix[top] = matrix[bottom];
            matrix[bottom] = temp;
            top++;
            bottom--;
        }

        //transpose

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

    }
}