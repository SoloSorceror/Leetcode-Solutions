class Solution {
public:
    string smallestPalindrome(string str) {
        if(str.size() == 1) return str;

        vector<int> freq(26,0);
        for(auto &s: str){
            freq[s-'a']++;
        }

        string ans = str;
        int left = 0, right = str.size()-1;
        char mid = '\0';

        for(int i=0; i<26; i++){
            while(freq[i] >=2){
                ans[left++] = ans[right--] = char('a' + i);
                freq[i] -= 2;
            }
            if(freq[i] == 1){
                mid = char('a' + i);
            }
        }
        if(mid != '\0'){
            ans[left] = mid;
        }
        return ans;
    }
};