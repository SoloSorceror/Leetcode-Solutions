class Solution {
private:
    int rec(int i, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notTake = rec(i+1,prev,nums,dp);
        int take = -1e9;
        if(prev == -1 || nums[i]>nums[prev]){
            take = 1 + rec(i+1,i,nums,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }
};