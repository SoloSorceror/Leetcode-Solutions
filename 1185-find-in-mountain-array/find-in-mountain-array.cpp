/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left)/2;

            // increasing side
            if(mountainArr.get(mid)< mountainArr.get(mid+1)){
                left = mid + 1;
            }
            // decrasing side
            else{
                right = mid;
            }
        }
        int peak = left;

        // search on the  left
        left = 0;
        right = peak;

        while(left<= right){
            int mid = left + (right - left)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            if(mountainArr.get(mid)< target){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }

        left = peak+1;
        right = mountainArr.length() - 1;

        while(left<= right){
            int mid = left + (right - left)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            if(mountainArr.get(mid)> target){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }

        return -1;
    }
};