class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;
        vector<int> res;
        for(auto &a: nums){
            map[a]++;
        }
        vector<vector<int>> ans(n+1);

        for(auto &a: map){
            ans[a.second].push_back(a.first);
        }
        for(int i = n; i>0; i--){ // no number has a 0 frequency genius
            for(auto a: ans[i]){
                if(res.size() == k) return res;
                res.push_back(a);
            }
        }
        return res;
    }
};