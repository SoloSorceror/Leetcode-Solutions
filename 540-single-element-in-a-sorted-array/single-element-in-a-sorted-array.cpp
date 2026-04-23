class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int first = 0, second =0;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(mid-1 >=0 && nums[mid-1] == nums[mid]){
                first = mid-1;
                second = mid;
            }else if(mid+1 <nums.size() && nums[mid+1] == nums[mid]){
                first = mid;
                second = mid+1;
            }else{
                return nums[mid];
            }

            if(first%2==0){
                left = second+1;
            }else{
                right = first-1;
            }
        }
        return -1;
    }
};