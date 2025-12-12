class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        long long prefix = 0;
        unordered_map<int,int> map;


        for(int i =0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        for(int i =0; i<n; i++){
            prefix += nums[i];

            if(prefix == 0){
                longest = i+1;
            }
            if(map.find(prefix) != map.end()){
                int l = map[prefix];
                longest = max(longest, i-l);
            }
            if(map.find(prefix) == map.end()){
                map[prefix] = i;
            }
        }
        return longest;

    }
};