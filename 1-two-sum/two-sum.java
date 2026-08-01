import java.util.*;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();

        for(int i=0; i<nums.length; i++){
            int need = target - nums[i];
            if(mp.containsKey(need)){
                return new int[] {i,mp.get(need)};
            }
            mp.put(nums[i],i);
        }
        return new int[] {0,0};
    }
}