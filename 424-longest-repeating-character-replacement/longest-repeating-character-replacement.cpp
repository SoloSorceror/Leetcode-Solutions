class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            int ch = s[i] -'A';
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
            int windowSize = i-left+1;

            if(windowSize - maxFreq >k){
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;
    }
};