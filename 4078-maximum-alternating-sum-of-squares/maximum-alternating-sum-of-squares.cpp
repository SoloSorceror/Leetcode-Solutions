class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        int mn = 40000, mx = 0;
        for (int x : nums) {
            int a = abs(x);
            mn = min(mn, a);
            mx = max(mx, a);
        }

        vector<int> cnt(mx - mn + 1, 0);
        for (int x : nums) {
            cnt[abs(x) - mn]++;
        }

        long long res = 0;
        int half = (n + 1) / 2;
        int processed = 0;

        for (int val = mx; val >= mn; val--) {
            long long sq = 1LL * val * val;
            int occurrences = cnt[val - mn];

            while (occurrences--) {
                if (processed < half) res += sq;  // positive slot
                else res -= sq;                  // negative slot
                processed++;
            }
        }

        return res;
    }
};
