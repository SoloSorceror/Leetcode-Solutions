class Solution {
    public int missingNumber(int[] nums) {
        int  n = nums.length;
        long sum = (long) (n*(n+1))/2;
        long curr = 0;

        for(int a: nums){
            curr +=a;
        }
        return (int) (sum - curr);
    }
}