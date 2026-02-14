class Solution {
public:
    int isValid(vector<int>& position, int m, int mid){
        int balls = 1;
        int lastPos = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i] - lastPos >= mid){
                balls++;
                lastPos = position[i];
                if(balls == m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int left = 1;
        int right = position[n-1] - position[0];
        int ans = 0;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(isValid(position,m,mid)){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};