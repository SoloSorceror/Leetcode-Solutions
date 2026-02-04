class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int s = nums.size();
        for(auto &a: nums){
            map[a]++;
        }
        vector<vector<int>> arr(s+1);
        for(auto &a: map){
            arr[a.second].push_back(a.first);
        }
        vector<int> ans;
        for(int i =s; i>=0; i--){
            for(auto &a: arr[i]){
                if(ans.size() == k) return ans;
                ans.push_back(a);
            }
        }
        return ans;
    }
};