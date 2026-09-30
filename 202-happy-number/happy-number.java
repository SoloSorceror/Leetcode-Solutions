class Solution {
    static long digitSquare(long n){
        long ans = 0;
        while(n>0){
            long temp = n%10;
            ans += temp*temp;
            n = n/10;
        }
        return ans;
    }
    public boolean isHappy(int n) {
        long temp = n;
        for(int i=0; i<10000; i++){
            long val = digitSquare(temp);
            if(val == 1) return true;
            temp = val;
        }
        return false;
    }
}