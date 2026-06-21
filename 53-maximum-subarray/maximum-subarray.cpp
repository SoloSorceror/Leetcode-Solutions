class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = -1e9;
        int curr = 0;

        for(auto&n: nums){
            curr += n;
            if(n>curr){
                curr = n;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};