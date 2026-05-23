class Solution {
public:
    bool check(string& small, string& big) {
        if (big.size() != small.size() + 1)
            return false;

        int i = 0;
        int j = 0;

        while (j < big.size()) {

            if (i < small.size() && small[i] == big[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == small.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        vector<int> lis;
        vector<int> length(n, 1);
        int count = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[prev], words[i]) &&
                    length[i] < length[prev] + 1) {
                    length[i] = length[prev] + 1;
                }
                count = max(count,length[i]);
            }
        }
        return count;
    }
};