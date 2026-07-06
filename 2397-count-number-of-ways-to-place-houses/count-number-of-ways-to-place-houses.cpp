class Solution {
public:
    int MOD = 1e9 + 7;

    long long rec(int n, int prev, vector<vector<int>>&dp){
        if(n==0) return 1;

        if(dp[n][prev] != -1) return dp[n][prev];

        long long notPlace = rec(n-1,0,dp) % MOD;
        long long place = 0;

        if(prev == 0){
            place = rec(n-1,1,dp) % MOD;
        }

        return dp[n][prev] = (place + notPlace) % MOD;
    }

    int countHousePlacements(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        long long curr = rec(n,0,dp);
        return (curr*curr) % MOD;
    }
};