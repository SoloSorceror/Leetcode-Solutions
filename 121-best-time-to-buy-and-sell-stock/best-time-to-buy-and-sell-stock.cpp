class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int prevBest = prices[0];
        for(int i=1; i<prices.size(); i++){
            int curr = 0;
            if(prices[i]> prevBest){
                curr = prices[i] - prevBest;
                maxProfit = max(maxProfit,curr);
            }
            if(prices[i]< prevBest){
                prevBest = prices[i];
            }
        }
        return maxProfit;
    }
};