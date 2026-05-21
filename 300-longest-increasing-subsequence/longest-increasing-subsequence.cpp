class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n,1);
        int maxi = 1;

        for(int i=1;i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]<nums[i]){
                    length[i] = max(1+length[prev],length[i]);
                }
                maxi = max(maxi,length[i]);
            }
        }
        return maxi;
    }
};