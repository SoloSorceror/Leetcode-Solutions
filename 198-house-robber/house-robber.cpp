class Solution {
public:
    int rob(vector<int>& nums) {
                int n = nums.size();
        if(n<=0) return 0;
        if(n==1) return nums[0];
        
        vector<int> dp(n);
        // dp[0] = arr[0];
        int first = nums[0];
        // dp[1] = max(arr[0], arr[1]);
        int second = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            // dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
            int ans = max(second, first+nums[i]);
            first = second;
            second = ans;
        }
        // return dp[n-1];
        return second;
    }
};