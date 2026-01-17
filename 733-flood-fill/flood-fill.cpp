class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int node = image[sr][sc];
        if(node == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            auto [r,c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == node){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};