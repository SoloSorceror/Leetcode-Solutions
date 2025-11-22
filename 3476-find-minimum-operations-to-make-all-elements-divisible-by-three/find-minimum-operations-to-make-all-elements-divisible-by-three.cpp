class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(auto &a: nums){
            if(a % 3 != 0){
                count++;
            }
        }
        return count;
    }
};