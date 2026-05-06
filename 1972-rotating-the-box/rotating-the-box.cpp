class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        // get a rotated array
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> arr(m,vector<char>(n,'.'));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[j][n-1-i] = boxGrid[i][j];
            }
        }

        for(int i=m-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(arr[i][j] == '#'){
                    int curr = i+1, prev = i;
                    while(curr<m && arr[curr][j] == '.'){
                        arr[curr][j] = arr[prev][j];
                        arr[prev][j] = '.';
                        curr++;
                        prev++;
                    }
                }
            }
        }
        return arr;
    }
};