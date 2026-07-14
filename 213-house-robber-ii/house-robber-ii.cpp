class Solution {
public:
    int func(vector<int>& nums){
        if (nums.size() == 1) return nums[0];
        int  n = nums.size();
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i=2; i<n; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        vector<int> num1(nums.begin(), nums.end() - 1);
        vector<int> num2(nums.begin() + 1, nums.end());
        return max(func(num1), func(num2));
    }
};