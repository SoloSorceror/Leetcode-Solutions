class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int arg = 0;

        for(auto &n : nums){
            if(count == 0){
                arg = n;
                count++;
            }
            else if(n == arg){
                count++;
            }
            else count--;
        }
        return arg;
    }
};