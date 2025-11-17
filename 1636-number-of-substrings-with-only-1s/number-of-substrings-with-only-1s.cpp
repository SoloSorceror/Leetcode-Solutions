class Solution {
public:
    const int P = int(1E9) + 7;
    int numSub(string s) {
        int p =0;
        long long ans = 0;
        while(p<s.size()){
            if(s[p] == '0'){
                ++p;
                continue;
            }
            long long count = 0;
            while(p<s.size() && s[p]=='1'){
                count++;
                ++p;
            }
            ans = ans + (1LL + count) * count/2;
            ans = ans % P;
        }
        return ans;
    }
};