class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distance(m, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    distance[i][j] =0;
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && distance[r][c] + 1< distance[nr][nc]){
                    q.push({nr,nc});
                    distance[nr][nc] = distance[r][c] + 1;
                }
            }
        }
        return distance;
    }
};