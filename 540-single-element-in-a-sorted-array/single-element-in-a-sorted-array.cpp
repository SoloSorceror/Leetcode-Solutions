class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorl = 0;
        for (int x: nums){
            xorl ^= x;
        }
        return xorl;
    }
};