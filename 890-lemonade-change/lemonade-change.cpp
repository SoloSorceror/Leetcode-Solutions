class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(2,0);
        for(int i=0; i<bills.size(); i++){
            int val = bills[i];
            if(val == 5) count[0]++;
            if(val == 10) count[1]++;

            int change = val - 5;
            if(change == 0) continue;
            while(change >= 10 && count[1] > 0){
                change -= 10;
                count[1]--;
            }
            while(change >= 5 && count[0] > 0){
                change -= 5;
                count[0]--;
            }
            if(change != 0) return false;
        }
        return true;
    }
};