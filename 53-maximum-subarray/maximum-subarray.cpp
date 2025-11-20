class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<=1) return nums[0];
        int currSum = nums[0];
        int maxi = nums[0];

        for(int i =1; i<nums.size(); i++){
            currSum = max(currSum + nums[i], nums[i]);
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
};