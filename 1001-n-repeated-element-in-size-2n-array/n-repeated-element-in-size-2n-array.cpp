class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] > 1) {   // 🔥 as soon as repeated found
                return x;
            }
        }
        return -1;
    }
};
