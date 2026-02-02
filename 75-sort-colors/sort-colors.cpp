class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int high = n-1;
        int itr = 0;

        while(itr<=high){
            if(nums[itr]==0){
                swap(nums[left],nums[itr]);
                left++;
                itr++;
            }
            else if(nums[itr]==2){
                swap(nums[itr],nums[high]);
                high--;
            }
            else{
                itr++;
            }
        }
    }
};