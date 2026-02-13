class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;      // min in right half
            } else {
                right = mid;         // min in left half including mid
            }
        }

        return nums[left];
    }
};
