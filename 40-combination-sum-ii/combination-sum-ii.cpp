class Solution {
public:
    void rec(int index, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i-1] == candidates[i]) continue;
            if(candidates[i]> target) break;
            ds.push_back(candidates[i]);
            rec(i+1,target-candidates[i],ds,ans,candidates);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        rec(0,target,ds,ans,candidates);
        return ans;
    }
};