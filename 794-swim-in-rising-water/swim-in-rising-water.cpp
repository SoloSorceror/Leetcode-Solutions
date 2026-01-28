class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int target){
        int n = grid.size();
        if(i<0 || j<0 || i>=n || j>= n || visited[i][j] || grid[i][j] > target){
            return false;
        }
        if (i== n-1 && j == n-1) return true;
        visited[i][j] = true;
        return dfs(i+1, j, grid, visited, target) || dfs(i-1, j, grid, visited, target) || dfs(i, j-1, grid, visited, target) || dfs(i, j+1, grid, visited, target);

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = n*n-1;

        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(dfs(0,0, grid, visited, mid)){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};