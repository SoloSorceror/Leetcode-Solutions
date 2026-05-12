class Solution {
public:
    bool isValid(int row, int col, vector<string> &board){
    int n = board.size();

    // upper diagonal left
    int r = row, c = col;
    while(r >= 0 && c >= 0){
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    // upper column
    r = row;
    c = col;
    while(r >= 0){
        if(board[r][c] == 'Q') return false;
        r--;
    }

    // upper diagonal right
    r = row;
    c = col;
    while(r >= 0 && c < n){
        if(board[r][c] == 'Q') return false;
        r--;
        c++;
    }

    return true;
}
    void rec(int idx, vector<string> &board, vector<vector<string>> &ans){
        int n = board.size();
        if(idx==n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(idx,i,board)){
                board[idx][i] = 'Q';
                rec(idx+1,board,ans);
                board[idx][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for(int i=0; i<n; i++) s+='.';
        vector<string> board(n,s);
        vector<vector<string>> ans;
        rec(0,board,ans);
        return ans;
    }
};