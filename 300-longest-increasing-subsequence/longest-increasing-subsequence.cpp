class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(auto &a: nums){
            auto itr = lower_bound(ans.begin(),ans.end(),a);
            if(itr==ans.end()){
                ans.push_back(a);
            }
            else *itr = a;
        }
        return ans.size();
    }
};