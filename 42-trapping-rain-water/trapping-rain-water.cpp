class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, count = 0;
        int maxLeft = 0, maxRight = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                maxLeft = max(maxLeft,  height[left]);
                count += max(0,maxLeft - height[left]);
                left++;
            }
            else{
                maxRight = max(maxRight, height[right]);
                count += max(0, maxRight - height[right]);
                right--;
            }
        }
        return count;
    }
};