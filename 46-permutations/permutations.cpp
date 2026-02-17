class Solution {
private:
    // Helper function to handle the backtracking
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: If we've fixed elements up to the end of the array,
        // we've found a complete permutation.
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Iterate through the array starting from 'start' index
        for (int i = start; i < nums.size(); ++i) {
            // 1. Swap: Fix the element at index 'i' to the 'start' position
            swap(nums[start], nums[i]);
            
            // 2. Recurse: Generate permutations for the rest of the array
            backtrack(nums, start + 1, result);
            
            // 3. Backtrack: Swap back to restore the array for the next iteration
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        // Start the backtracking process from index 0
        backtrack(nums, 0, result);
        return result;
    }
};