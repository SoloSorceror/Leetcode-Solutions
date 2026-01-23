class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        // ONLY right & down
        int dr[2] = {0, 1};
        int dc[2] = {1, 0};

        while(!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            if(d > dist[r][c]) continue;

            for(int i = 0; i < 2; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < n && nc < m) {
                    int nd = d + grid[nr][nc];
                    if(nd < dist[nr][nc]) {
                        dist[nr][nc] = nd;
                        pq.push({nd, {nr, nc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
