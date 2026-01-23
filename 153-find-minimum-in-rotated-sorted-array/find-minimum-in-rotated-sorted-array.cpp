class Solution {
public:
    int findMin(vector<int>& nums) {
        int start= 0, end = nums.size() - 1;
        int n = nums.size();

        while(start <= end){

            int mid = start + (end - start)/2;
            if(nums[mid] > nums[n-1]){
                start = mid + 1;
            }
            else{
                end = mid -1;
                // ans = nums[mid];
            }
        }
        return nums[start];
    }
};