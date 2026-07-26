class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1e9;
        int max2 = -1e9;
        int max3 = -1e9;

        int min1 = 1e9;
        int min2 = 1e9;

        for (auto& n : nums) {
            if (true) {
                if (n > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = n;
                } else if (n > max2) {
                    max3 = max2;
                    max2 = n;
                } else if (n > max3) {
                    max3 = n;
                }
            }

            if (true) {
                if (n < min1) {
                    min2 = min1;
                    min1 = n;
                } else if (n < min2) {
                    min2 = n;
                }
            }
        }

        long long v1 = max1 * max2 * max3;
        long long v2 = min1 * min2 * max1;

        return max(v1, v2);
    }
};