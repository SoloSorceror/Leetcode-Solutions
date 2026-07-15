class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return rec(0,nums,dp);
    }

private:
    int rec(int index, vector<int>& nums, vector<int> &dp){
        int n = nums.size();
        if(index == n-1) return 1;
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        int ans = 0;

        for(int j=1; j<= nums[index]; j++){
            ans = ans || rec(index+j,nums,dp);
            if(ans) return true;
        }
        return  dp[index] = ans;
    }
};