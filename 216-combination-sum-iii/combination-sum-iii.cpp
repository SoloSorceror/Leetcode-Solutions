class Solution {
public:
    void rec(int idx, int size, int target, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){
        if(target==0 && curr.size() == size){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i-1] == nums[i]) continue;
            if(target<nums[i]) break;
            curr.push_back(nums[i]);
            rec(i+1,size,target-nums[i],nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        rec(0,k,n,nums,curr,ans);
        return ans;
    }
};