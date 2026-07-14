class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+1,0);
        const int LIMIT = INT_MAX;
        dp[0] = 1;
        for(int i=0; i<coins.size(); i++){
            int wt = coins[i];
            for(int j=wt; j<= amount; j++){
                if (dp[j] > INT_MAX - dp[j - wt]) {
                    dp[j] = INT_MAX;
                } else {
                    dp[j] = dp[j] + dp[j - wt];
                }
            }
        }
        return (int)dp[amount];
    }
};