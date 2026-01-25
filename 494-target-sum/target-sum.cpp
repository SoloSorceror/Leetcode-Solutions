class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > total) return 0;

        int sum = (target + total)/2;
        if((target + total) % 2 != 0) return 0;
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                dp[i][j] = dp[i-1][j];

                if(j>= nums[i-1]){
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};