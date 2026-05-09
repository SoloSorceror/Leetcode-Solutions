class Solution {
public:
    void rec(int index, long long &number, string s, int sign){
        int n = s.size();
        if(index >= n) return;
        if(isdigit(s[index])){
            int digit = s[index] - '0';
            if(number > (INT_MAX - digit)/10){
                number = sign==1? INT_MAX:INT_MIN;
                return;
            }
            number = number*10 + digit;
            rec(index+1,number,s,sign);
        }else return;
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long number = 0;

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n && s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }

        rec(i,number,s,sign);
        return number*sign;
    }
};