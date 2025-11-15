class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, maj = 0;
        for(int a : nums){
            if(count == 0){
                maj = a;
                count++;
            }else if (a==maj){
                count++;
            }else{
                count--;
            }
        }
        return maj;
    }
};