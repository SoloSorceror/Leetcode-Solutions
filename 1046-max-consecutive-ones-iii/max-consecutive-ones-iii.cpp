class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int alias = 0;
        int ptr = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                alias++;
                while(alias>k && ptr <= i){
                    if(nums[ptr] == 0){
                        alias--;
                    }
                    ptr++;
                }
            }
            maxi = max(maxi,i-ptr+1);
        }
        return maxi;
    }
};