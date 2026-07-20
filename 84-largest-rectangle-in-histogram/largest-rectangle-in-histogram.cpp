class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        vector<int> nse(n,n);
        vector<int> pse(n,-1);

        //calculate nse
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }

        // calculate pse
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                pse[i] = s.top();
            }
            s.push(i);
        }

        int maxi = 0;

        for(int i=0; i<n; i++){
            int temp = nse[i] - pse[i] - 1;
            maxi = max(maxi, temp*heights[i]);
        }
        return maxi;
    }
};