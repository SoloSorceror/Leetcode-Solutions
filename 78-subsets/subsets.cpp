class Solution {
public:
    void rec(int index,vector<int> &curr,vector<int> &nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        rec(index+1,curr,nums,ans);
        curr.pop_back();
        rec(index+1,curr,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        rec(0,curr,nums,ans);
        return ans;
    }
};