class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> map;
        int count = 0;
        long long sum = 0;
        int  n = nums.size();

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum == k) count++;
            int need = sum - k;
            
            if(map.find(need)!= map.end()){
                count += map[need];
            }
            map[sum]++;
        }
        return count;
    }
};