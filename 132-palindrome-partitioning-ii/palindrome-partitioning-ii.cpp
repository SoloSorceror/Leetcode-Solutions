class Solution {
public:
    int rec(int i, int n, string &s, vector<int> &dp){
        
        if(i==n) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j=i; j<n; j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + rec(j+1,n,s,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n,-1);
        // The number of cuts is always (number of substrings - 1).
        return rec(0,n,s,dp)-1;
    }

private:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

};