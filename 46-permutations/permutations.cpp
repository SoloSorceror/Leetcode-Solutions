class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> result;
    vector<int>path;
    
    void backtrack(vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i<nums.size(); ++i){

            if(visited[i]) continue;

            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.assign(nums.size(), false);
        backtrack(nums);
        return result;
    }
};