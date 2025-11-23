class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;

        for (int x : nums) {
            vector<int> newdp = dp;
            for (int r = 0; r < 3; r++) {
                if (dp[r] == INT_MIN) continue;
                int nr = (r + x) % 3;
                newdp[nr] = max(newdp[nr], dp[r] + x);
            }
            dp = newdp;
        }
        return dp[0];
    }
};
