class Solution {
public:
    int MOD = 1e9 + 7;

    int power(long long value, long long N){
        int result = 1;
        value = value % MOD;
        while(N>0){
            if(N&1){
                result = (result * value) % MOD;
            }
            value = (value * value) % MOD;
            N >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        if(n==0) return 0;
        long long even = (n+1)/2;
        long long odd = (n/2);
        
        long long first = power(5,even);
        long long second = power(4,odd);
        return (first * second) % MOD;
    }
};