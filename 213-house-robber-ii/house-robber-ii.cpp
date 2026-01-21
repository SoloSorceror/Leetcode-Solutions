class Solution {
public:
    int func(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n);
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int ans = max(second, first + nums[i]);
            first = second;
            second = ans;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> num1(nums.begin(), nums.end() - 1);
        vector<int> num2(nums.begin() + 1, nums.end());
        return max(func(num1), func(num2));
    }
};