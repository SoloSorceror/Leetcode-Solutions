class Solution {
public:
    int canEat(vector<int>& piles, int h, int speed){
        int time = 0;
        for(int i=0; i<piles.size(); i++){
            time+= (piles[i] + speed -1)/speed;
            if(time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(left<= right){
            int mid = left + (right-left)/2;
            if(canEat(piles,h,mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};