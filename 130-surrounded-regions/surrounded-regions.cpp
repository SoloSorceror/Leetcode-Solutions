class Solution {
public:

    void dfs(int row, int col,vector<vector<char>>& board,vector<vector<bool>> &visited, int dx[], int dy[]){
        visited[row][col] = true;
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                dfs(nrow,ncol,board,visited,dx,dy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        //column check
        for(int i=0; i<n; i++){
            if(board[0][i]== 'O' && !visited[0][i]){
                dfs(0,i,board,visited,dx,dy);
            }
            if(board[m-1][i]=='O' && !visited[m-1][i]){
                dfs(m-1,i,board,visited,dx,dy);
            }
        }

        // border row check

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i,0,board,visited,dx,dy);
            }
            if(board[i][n-1] == 'O' && !visited[i][n-1]){
                dfs(i,n-1,board,visited,dx,dy);
            }
        }

        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};