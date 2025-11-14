class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 1, count = 0;

        while (l < n && r < n) {
            if (l == r) {
                r++;
                continue;
            }

            int diff = nums[r] - nums[l];

            if (diff == k) {
                count++; 
                int sameL = nums[l], sameR = nums[r];

                // skip duplicates
                while (l < n && nums[l] == sameL) l++;
                while (r < n && nums[r] == sameR) r++;
            }
            else if (diff < k) {
                r++;
            } 
            else {
                l++;
            }
        }

        return count;
    }
};
