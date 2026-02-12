class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int left = 0;
        int count = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        return helper(nums, k) - helper(nums, k - 1);
    }
};