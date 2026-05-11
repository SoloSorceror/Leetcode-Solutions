class Solution {
public:
    void rec(int idx, vector<int>& nums,vector<int> &curr,vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i-1]==nums[i]) continue;
            if(nums[i]>target) break;
            curr.push_back(nums[i]);
            rec(i+1,nums,curr,ans,target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,curr,ans,target);
        return ans;
    }
};