class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool first = true;
        int gap = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]== 1 && first == true){
                first = false;
                gap = 0;
                continue;
            }
            if(nums[i]==1 && first == false){
                if(gap<k) return false;
                gap = 0;
            }
            else gap++;
        }
        return true;
    }
};