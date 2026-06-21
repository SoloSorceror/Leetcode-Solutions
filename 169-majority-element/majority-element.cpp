class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = 0;
        int count = 0;
        for(auto &a: nums){
            if(a==majority){
                count++;
            }
            else if(count == 0){
                majority = a;
                count++;
            }
            else count--;
        }
        return majority;
    }
};