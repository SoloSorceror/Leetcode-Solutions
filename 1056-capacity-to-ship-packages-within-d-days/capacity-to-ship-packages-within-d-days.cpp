class Solution {
public:
    int canShip(vector<int>& weights, int days, int mid){
        int time = 1;
        int sum = 0;
        for(auto &w: weights){
            if(sum + w > mid){
                time++;
                sum = w;
            }
            else sum += w;
        }
        return time <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(canShip(weights,days,mid)){
                ans = mid;
                right = mid -1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};