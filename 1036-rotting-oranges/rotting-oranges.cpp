class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    visited[i][j] = 1;
                    fresh++;
                }
            }
        }

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        int time = 0;

        while(!q.empty() && fresh>0){
            int sz = q.size();
            time++;
            while(sz--){
                auto [row,col] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nr = row + dx[i];
                    int nc = col + dy[i];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc] == 1){
                        q.push({nr,nc});
                        visited[nr][nc] = 2;
                        fresh--;
                    }
                }

            }
        }
        return fresh == 0 ? time : -1;
    }
};