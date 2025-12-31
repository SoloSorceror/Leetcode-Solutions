class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int V = grid.size();
        if (grid[0][0] == 1 || grid[V - 1][V - 1] == 1)
            return -1;

        vector<vector<int>> dist(V, vector<int>(V, -1));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 1;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r == V - 1 && c == V - 1)
                return dist[r][c];

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < V && nc >= 0 && nc < V &&
                    grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};