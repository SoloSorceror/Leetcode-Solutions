class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int total_sum = 0 , count = 0;

        for(int i =0; i<nums.size(); i++){
            total_sum += nums[i];
            int x = total_sum - k;
            if(map.find(x) != map.end()){
                count += map[x];
            }
            map[total_sum] ++;
        }
        return count;

    }
};