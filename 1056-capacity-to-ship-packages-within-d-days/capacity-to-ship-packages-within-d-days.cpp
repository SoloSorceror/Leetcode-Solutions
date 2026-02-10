class Solution {
public:
    bool canShip(int mid,vector<int>& weights, int days){
        int count = 1;
        int sum = 0;
        for(auto &a: weights){
            if(sum+a>mid){
                sum = a;
                count++;
            }
            else{
                sum +=a;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canShip(mid,weights,days)){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};