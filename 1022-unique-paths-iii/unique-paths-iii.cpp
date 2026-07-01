class Solution {
public:
    int answer = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int row, int col, int endRow, int endCol, int emptySquares, int stepsTaken, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (row == endRow && col == endCol) {
            if (stepsTaken == emptySquares + 1) {
                return 1;
            }
            return 0;
        }

        int temp = grid[row][col];
        grid[row][col] = 4;

        int validPaths = 0;

        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 4) {
                validPaths += dfs(nr, nc, endRow, endCol, emptySquares,stepsTaken + 1, grid);
            }
        }

        grid[row][col] = temp;
        return validPaths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = 0, col = 0;
        int endRow = 0, endCol = 0;
        int emptySquares = 0;
        int n = grid.size();
        int m = grid[0].size();

        // Initial scan to find start, end, and count empty squares
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                } else if (grid[i][j] == 2) {
                    endRow = i;
                    endCol = j;
                } else if (grid[i][j] == 0) {
                    emptySquares++;
                }
            }
        }

        // Kick off DFS with 0 steps taken
        return dfs(row, col, endRow, endCol, emptySquares, 0, grid);
    }
};