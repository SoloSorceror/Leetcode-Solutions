class Solution {
    public int removeDuplicates(int[] nums) {
        // have a left pointer, and iterate right if same value skip and diff then increment left and then swap with right

        int left = 0;

        for(int right = 0; right<nums.length; right++){
            if(nums[left] != nums[right]){
                left++;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
}