class Solution {
public:
    int dp[601][101][101]; // dp[i][zerosLeft][onesLeft]
    
    int solve(int i, int zerosLeft, int onesLeft, 
              vector<pair<int,int>>& count, vector<string>& strs) {
        
        // base case
        if (i == strs.size()) return 0;
        
        // memo check
        if (dp[i][zerosLeft][onesLeft] != -1)
            return dp[i][zerosLeft][onesLeft];
        
        int zeros = count[i].first;
        int ones = count[i].second;
        
        // option 1: skip
        int skip = solve(i + 1, zerosLeft, onesLeft, count, strs);
        
        // option 2: take (if fits)
        int take = 0;
        if (zeros <= zerosLeft && ones <= onesLeft) {
            take = 1 + solve(i + 1, zerosLeft - zeros, onesLeft - ones, count, strs);
        }
        
        // store result
        return dp[i][zerosLeft][onesLeft] = max(skip, take);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        
        // precompute zero/one count
        vector<pair<int,int>> count;
        for (auto &s : strs) {
            int z = 0, o = 0;
            for (char c : s) {
                if (c == '0') z++;
                else o++;
            }
            count.push_back({z, o});
        }
        
        return solve(0, m, n, count, strs);
    }
};
