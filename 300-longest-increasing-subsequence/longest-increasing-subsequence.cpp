class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int n: nums){
            auto it = lower_bound(ans.begin(),ans.end(), n);
            if(it==ans.end()){
                ans.push_back(n);
            }
            else *it = n;
        }
        return ans.size();
    }
};