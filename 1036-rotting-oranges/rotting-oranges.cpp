class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;

        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh>0){
            int size = q.size();
            time++;

            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};

            for(int i=0; i<size; i++){
                auto [r,c] = q.front();
                q.pop();

                for(int k =0; k<4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                } 
            }
        }
        return fresh==0 ? time : -1;

    }
};