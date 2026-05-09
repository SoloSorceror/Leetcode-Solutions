class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long number = 0;

        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && s[i] == '-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(number > (INT_MAX-digit)/10){
                return sign==1? INT_MAX: INT_MIN;
            }
            number = number * 10 + digit;
            i++;
        }
        return number*sign;
    }
};