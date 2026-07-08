class Solution {
public:

    int rec(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k=i; k<j; k++){
            int temp = nums[i-1] * nums[j] * nums[k] + rec(i,k,nums,dp) + rec(k+1,j,nums,dp);
            ans = max(temp,ans);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int  n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(1,n-1,nums,dp);
    }
};