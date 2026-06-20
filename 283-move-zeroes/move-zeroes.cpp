class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i=1; i<n; i++){
            if(nums[ptr]==0 && nums[i] != 0){
                swap(nums[ptr],nums[i]);
                ptr++;
            }
            else if(nums[ptr] != 0) ptr++;
        }
    }
};