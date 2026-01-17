class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // distance array with every point initialised to inf, set values with 1 as zero push them in q, do a bfs
        // 4 directional array pushevery node with 1, do bfs and store distance with min dist 
        // iterate the distance array and store the maxi // we can optimize this by storing the maxi while run time itself

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if (q.empty() || q.size() == n * m) return -1;

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int distance = -1;

        while(!q.empty()){
            int s = q.size();
            distance++;
            for(int i=0; i<s; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        grid[nr][nc] = 1; // mark visited directly in grid
                        q.push({nr,nc});
                    }
                }
            }
        }
        return distance;
    }
};