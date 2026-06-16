class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = 1e9;
        int bestAns = 1e9;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0; i<n-2; i++){
            int start = i+1, end = n-1;
            int currSum = 0;

            while(start<end){
                currSum = nums[i] + nums[start] + nums[end];
                
                if(currSum == target) return target;

                if(abs(currSum - target)< minDiff){
                    minDiff = abs(currSum - target);
                    bestAns = currSum;
                }

                if(currSum < target) start++;
                else end--;
            }

        }
        return bestAns;
    }
};