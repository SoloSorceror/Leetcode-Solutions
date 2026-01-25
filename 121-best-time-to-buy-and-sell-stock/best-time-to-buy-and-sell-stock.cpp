class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = 0;
        int value = 0;
        for(int i=1; i<n; i++){
            if(prices[i] < prices[mini]){
                mini = i;
            }
            value = max(value, prices[i] - prices[mini]);
        }
        return value;
    }
};