class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        long long sum = 0;
        int count = 0;

        for(auto &a: nums){
            sum +=a;
            int target = sum - k;
            if(map.find(target) != map.end()){
                count += map[target];
            }
            map[sum] ++;
        }
        return count;
    }
};