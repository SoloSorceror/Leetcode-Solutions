class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long val1 = nums[0] * nums[1] * nums[n-1];
        long long val2 = nums[n-1] * nums[n-2] * nums[n-3];
        return max(val1,val2);
    }
};