class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        int sum = 0;
        for(auto &x: nums){
            sum += x;
            if(x> sum){
                sum = x;
            }
            maximum = max(maximum,sum);
        }
        return maximum;

    }
};