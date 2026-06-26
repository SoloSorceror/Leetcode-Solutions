class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int maxi = 0;

        vector<int> dp(s2+1);

        for (int i = 1; i < s1 + 1; i++) {
            int diag = 0;
            for (int j = 1; j < s2 + 1; j++) {
                int temp = dp[j];
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + diag;
                } else {
                    dp[j] = 0;
                }
                diag = temp;
                maxi = max(maxi, dp[j]);
            }
        }
        return maxi;
    }
};