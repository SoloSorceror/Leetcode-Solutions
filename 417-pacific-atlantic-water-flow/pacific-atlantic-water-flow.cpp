class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &heights){
        if(visited[row][col]) return;
        visited[row][col] = 1;

        int n = heights.size();
        int m = heights[0].size();

        for(int i=0; i<4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && heights[nr][nc] >= heights[row][col]){
                dfs(nr,nc,visited,heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacificVisited(n,vector<int>(m,0));
        vector<vector<int>> atlanticVisited(n,vector<int>(m,0));

        for(int i=0; i<m; i++){
            dfs(0,i,pacificVisited,heights);
            dfs(n-1, i, atlanticVisited,heights);
        }

        for(int i=0; i<n; i++){
            dfs(i,0,pacificVisited,heights);
            dfs(i,m-1,atlanticVisited,heights);
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlanticVisited[i][j] && pacificVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};