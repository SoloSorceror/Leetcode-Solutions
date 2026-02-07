class Solution {
public:
    void sortColors(vector<int>& nums) {
        int itr = 0;
        int low = 0;
        int high = nums.size()-1;

        while(itr<=high){
            if(nums[itr] == 0){
                swap(nums[itr++],nums[low++]);
            }
            else if(nums[itr] == 2){
                swap(nums[itr],nums[high--]);
            }
            else{
                itr++;
            }
        }
    }
};