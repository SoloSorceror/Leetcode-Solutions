class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int time = 0;

        // Step 2: Multi-source BFS
        while(!q.empty() && fresh > 0){
            int sz = q.size();
            time++;

            for(int i = 0; i < sz; i++){
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;   // mark rotten
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
