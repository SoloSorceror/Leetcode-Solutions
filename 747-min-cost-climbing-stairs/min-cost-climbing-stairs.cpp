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
        vector<int> dp(n+1,-1);
        return rec(n,cost,dp);
    }
};