class Solution {
public:
    int MOD = 1e9 + 7;

    int countHousePlacements(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        long long one_way = rec(n,0,dp);
        return (one_way*one_way) % MOD;
    }
    
private:
    long long rec(int index, int prev, vector<vector<int>> &dp){
        if(index == 0) return 1;

        if(dp[index][prev] != -1) return dp[index][prev];

        long long ways = 0;

        ways = (ways + rec(index-1,0,dp)) % MOD;

        if(prev == 0){
            ways = (ways + rec(index-1,1,dp)) % MOD;
        }
        return dp[index][prev] = ways;
    }
};