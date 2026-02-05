class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128,0);
        int maxi = 0;
        int ptr = 0;
        for(int i=0; i<s.size(); i++){
            while(count[s[i]] >0){
                count[s[ptr]]--;
                ptr++;
            }
            maxi = max(maxi, i-ptr+1);
            count[s[i]]++;
        }
        return maxi;
    }
};