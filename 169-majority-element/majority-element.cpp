class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;

        for(auto &n: nums){
            if(n==majority) count++;
            else if(count == 0){
                majority = n;
                count++;
            }
            else count--;
        }
        return majority;
    }
};