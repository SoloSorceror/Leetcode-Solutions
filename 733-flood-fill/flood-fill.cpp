class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == original){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};