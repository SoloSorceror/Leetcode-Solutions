class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int qsize = queries.size();
        if(qsize == 0 ) return ans;

        for (int p = 0; p < qsize; p++) {
            int q1 = queries[p][0];
            int q2 = queries[p][1];
            int q3 = queries[p][2];
            int q4 = queries[p][3];
            for (int i = q1; i <= q3; i++) {
                for (int j = q2; j <= q4; j++) {
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};