class Solution {
public:

    int rec(int index, vector<int> &cost, vector<int> &dp) {
        if(index <= 1) return 0;

        if(dp[index] != -1) return dp[index];

        int one = rec(index-1, cost, dp) + cost[index-1];
        int two = rec(index-2, cost, dp) + cost[index - 2];

        return dp[index] = min(one,two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        //return rec(n,cost,dp);

        dp[0] = 0;
        dp[1] = 0;

        for(int i=2; i<= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};