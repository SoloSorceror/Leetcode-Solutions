class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1: st.top();
                int nse = i;

                maxi = max(maxi, (nse - pse - 1) * element);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1: st.top();
            int nse = n;

            maxi = max(maxi, (nse - pse - 1) * element);
        }
        return maxi;
    }
};