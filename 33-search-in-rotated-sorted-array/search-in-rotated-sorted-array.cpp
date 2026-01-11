class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() -1;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid -1;
                } else{
                    start = mid + 1;
                }
            } else { // Right half is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1; // Search in right half
                } else {
                    end = mid - 1; // Search in left half
                }
            }

        }
        return -1;
        
    }
};