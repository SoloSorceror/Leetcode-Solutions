class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m+1,0);

        for(int j =0; j<=m; j++){
            dp[j] = j;
        }

        for(int i=1; i<=n; i++){
            int diag = dp[0];
            dp[0] = i;
            for(int j=1; j<=m; j++){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]) dp[j] = diag;
                else dp[j] = min({dp[j], dp[j-1], diag}) + 1;
                diag = temp;
            }
        }
        return dp[m];
    }
};