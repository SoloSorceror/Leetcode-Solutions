class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        long long place = 1;
        while(n!=0){
            int ab = n % 10;
            if(ab != 0){
                ans += ab * place;
                place *=10;
            }
            n/=10;
        }
        return ans;
    }
};