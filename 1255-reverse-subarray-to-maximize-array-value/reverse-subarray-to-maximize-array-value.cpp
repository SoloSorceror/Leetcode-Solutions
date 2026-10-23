class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int maxGain = 0;
        
        // Variables to find the max gain for the "middle subarray" case
        int min_of_maxs = INT_MAX;
        int max_of_mins = INT_MIN;

        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i];
            int b = nums[i + 1];
            int currentDiff = abs(a - b);
            
            totalSum += currentDiff;
            
            // Track the extremes for middle subarray reversal
            min_of_maxs = min(min_of_maxs, max(a, b));
            max_of_mins = max(max_of_mins, min(a, b));
            
            // Case 1: Reversing a prefix (0 to i)
            // Reconnecting nums[0] to nums[i+1]
            maxGain = max(maxGain, abs(nums[0] - b) - currentDiff);
            
            // Case 2: Reversing a suffix (i+1 to n-1)
            // Reconnecting nums[n-1] to nums[i]
            maxGain = max(maxGain, abs(nums[n - 1] - a) - currentDiff);
        }
        
        // Case 3: Reversing a middle subarray
        // The max gain is 2 * (largest minimum of a pair - smallest maximum of a pair)
        int middleGain = 2 * (max_of_mins - min_of_maxs);
        maxGain = max(maxGain, middleGain);
        
        return totalSum + maxGain;
    }
};