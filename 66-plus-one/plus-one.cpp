class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = false;

        for(int i=n-1; i>=0; i--){
            int temp = (digits[i] + 1) %10;
            if(temp == 0){
                digits[i] = 0;
                carry = true;
                continue;
            }
            else{
                digits[i] = temp;
                carry = false;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};