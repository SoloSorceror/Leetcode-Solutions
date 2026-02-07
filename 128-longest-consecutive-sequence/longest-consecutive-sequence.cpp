class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maximum = 0;
        for(int x: st){
            int count = 0;
            if(st.find(x-1) == st.end()){
                count++;
                while(st.find(x+1) != st.end()){
                    x++;
                    count++;
                }
                maximum = max(maximum,count);
            }
        }
        return maximum;
    }
};