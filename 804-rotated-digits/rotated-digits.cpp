class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i=0; i<=n; i++){
            int check = i;
            bool isValid = true;
            bool changed = false;

            while(check > 0 && isValid){
                int val = check % 10;
                if(val == 3 || val == 4 || val == 7) isValid = false;
                else if(val == 2 || val == 5 || val == 6 || val == 9) changed = true;
                check /= 10;
            }
            if(isValid && changed) count++;
        }
        return count;
    }
};