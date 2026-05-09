class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double result = 1.0;
        if(N<0){
            x = 1.0/x;
            N = -N;
        }
        while(N>0){
            if(N&1) result *= x;
            x *= x;
            N >>= 1;
        }
        return result;
    }
};