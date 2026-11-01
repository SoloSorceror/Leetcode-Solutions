class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            int val = heights[i] * (nse[i] - pse[i] -1);
            maxi = max(maxi,val);
        }
        return maxi;
    }
};