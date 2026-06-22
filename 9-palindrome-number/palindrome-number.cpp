class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long initial = x;
        long long newNo = 0;
        while(x>0){
            newNo = newNo*10 + x%10;
            x/=10;
        }
        return newNo == initial;
    }
};