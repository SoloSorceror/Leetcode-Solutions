class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto &a : nums){
            map[a]++;
        }
        int ans = 0;
        int maxi = INT_MIN;
        for(auto &a: map){
            if(a.second> maxi){
                maxi = a.second;
                ans = a.first;
            }
        }
        return ans;
    }
};