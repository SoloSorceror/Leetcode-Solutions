class Solution {
public:
    bool canEat(int speed, vector<int>& piles, int h){
        int time = 0;
        for(auto &p: piles){
            time += (p+speed-1)/speed;
            if(time>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = 0;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(canEat(mid,piles,h)){
                right = mid -1;
                ans = mid;
            }
            else left = mid+1;
        }
        return ans;
    }
};