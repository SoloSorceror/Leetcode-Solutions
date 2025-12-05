class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1);
        int count = 0;
        prefix[0] = 0;

        for(int i =1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int total = prefix[n];

        for(int i = 1; i<n; i++){
            int x = total - prefix[i] - prefix[i];
            if(x%2 == 0){
                count++;
            }
        }
        return count;  
    }
};