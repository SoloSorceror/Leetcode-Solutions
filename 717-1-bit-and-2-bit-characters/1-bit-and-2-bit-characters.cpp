class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1) return true;
        bool ans = false;
        int last = bits[0];

        for(int i=1; i<bits.size(); i++){
            if(last == 1){
                ans = false;
                last = 0;
                continue;
            }
            else{
                last = bits[i];
                ans = true;
            }
        }
        return ans;
    }
};