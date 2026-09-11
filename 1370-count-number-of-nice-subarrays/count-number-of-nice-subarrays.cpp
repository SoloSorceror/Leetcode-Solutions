class Solution {
public:
    int helper(vector<int> &nums, int goal){
        if(goal<0) return 0;

        int left = 0;
        int curr = 0;
        int count = 0;

        for(int right =0; right<nums.size(); right++){
            curr += nums[right];

            while(curr > goal){
                curr -= nums[left];
                left++;
            }
            count += right-left+1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> nums(n,0);

        for(int i=0; i<arr.size(); i++){
            if(arr[i]%2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }
        return helper(nums,k) - helper(nums,k-1);
    }
};