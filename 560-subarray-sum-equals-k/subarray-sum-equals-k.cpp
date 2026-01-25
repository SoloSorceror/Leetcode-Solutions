class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> map;
        // map[0] = 1;
        long long sum = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                count++;
            }
            int need = sum - k;
            if(map.find(need) != map.end()){
                count += map[need];
            }
            map[sum]++;
        }
        return count;
    }
};