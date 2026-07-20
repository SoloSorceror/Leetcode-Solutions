class Solution {
private:
    int helper(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1: st.top();

                maxi = max(maxi, element * (i-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1: st.top();

            maxi = max(maxi, element * (n-pse-1));
        }
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0){
                    dp[0][j] = matrix[0][j] - '0';
                }
                else if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + dp[i-1][j];
                }
            }
        }


        int maxi = 0;

        for(int i=0; i<n; i++){
            vector<int> temp(dp[i].begin(),dp[i].end());
            maxi = max(maxi,helper(temp));
        }
        return maxi;
    }
};