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
        vector<int> before(n+1,0), curr(n+1,0);

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){

                int notTake = before[prev+1];
                int take = 0;

                if(prev==-1 || nums[i]>nums[prev]){
                    take = 1 + before[i+1];
                }
                curr[prev+1] = max(take,notTake);
            }
            before = curr;
        }
        return curr[0];
    }
};