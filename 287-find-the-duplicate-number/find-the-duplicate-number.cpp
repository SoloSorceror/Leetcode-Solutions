class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &a: nums){
            if(st.count(a)) return a;
            st.insert(a);
        }
        return 0;
    }
};