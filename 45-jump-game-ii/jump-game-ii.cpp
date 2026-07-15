class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        dp[n-1] = 0;

        for(int i=n-2; i>=0; i--){
            for(int j=1; j<= nums[i]; j++){
                if(i+j<n){
                    dp[i] = min(dp[i], 1 + dp[i+j]);
                }
            }
        }
        return dp[0];
    }
private:
    int rec(int index, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(index == n-1) return 0;
        if(index >= n) return 1e9;

        if(dp[index] != -1) return dp[index];

        int mini = 1e9+7;

        for(int j=1; j<= nums[index]; j++){
            mini = min(mini, 1 + rec(index+j,nums,dp));
        }
        return dp[index] = mini;
    }
};