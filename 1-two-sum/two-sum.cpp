class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            int f = target - nums[i];
            if(map.find(f)!= map.end()){
                return {map[f],i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};