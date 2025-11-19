class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (auto& a : st) {
            if (st.find(a - 1) == st.end()) {
                int length = 1;
                while (st.find(a + length) != st.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};