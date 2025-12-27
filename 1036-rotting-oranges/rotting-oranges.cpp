class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time =0;
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && fresh>0){
            int size = q.size();
            time++;

            for(int i=0; i<size;i++){
                auto [r,c] = q.front();
                q.pop();

                for(int k =0; k<4; k++){
                    int nr = r + delRow[k];
                    int nc = c + delCol[k];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] ==1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
};