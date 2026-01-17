class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // distance array with every point initialised to inf, set values with 1 as zero push them in q, do a bfs
        // 4 directional array pushevery node with 1, do bfs and store distance with min dist 
        // iterate the distance array and store the maxi // we can optimize this by storing the maxi while run time itself

        int n = grid.size();
        int m = grid[0].size();
        int maxi = -1;
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && distance[r][c] + 1 < distance[nr][nc]){
                        distance[nr][nc] = distance[r][c] + 1;
                        maxi = max(maxi,distance[r][c] + 1);
                        q.push({nr,nc});
                    }
                }
            }
        }
        return maxi;
    }
};