class Solution {
public:
    int upperBound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();

        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        return upperBound(nums,target);
    }
};