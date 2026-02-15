class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid){
        int split = 1;
        int curr = 0;

        for(auto x: nums){
            if(curr + x > mid){
                split++;
                curr = x;
            }else{
                curr+=x;
            }
        }
        return split<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        if (nums.size() < k)
            return 0;

        while (low <= high) {
            int mid = low + (high-low)/2;
            if(canSplit(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};