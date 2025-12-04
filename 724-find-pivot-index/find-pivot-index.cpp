class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i =1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int total = prefix[n];

        for(int i =0; i<n;i++){
            int left = prefix[i];
            int right = total - prefix[i+1];
            if(left == right) return i;
        }
        return -1;
    }
};