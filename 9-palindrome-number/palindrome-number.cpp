class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int initial = x;
        long  newNo = 0;
        while(x>0){
            newNo = newNo*10 + x%10;
            if(newNo > INT_MAX) return false;
            x/=10;
        }
        return (int)newNo == initial;
    }
};