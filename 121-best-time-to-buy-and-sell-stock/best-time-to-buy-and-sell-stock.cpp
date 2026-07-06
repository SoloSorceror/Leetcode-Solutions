class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = prices[0];
        int ans = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] < maxVal) maxVal = prices[i];
            else ans = max(ans,prices[i] - maxVal);
        }
        return ans;
    }
};