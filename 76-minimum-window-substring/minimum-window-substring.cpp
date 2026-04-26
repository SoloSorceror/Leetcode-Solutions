class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> freq(256,0);
        int count = 0;
        int left = 0;
        int minWindowSize = INT_MAX;
        int startIdx = 0;

        for(char c: t){
            freq[c]++;
            count++;
        }

        for(int right=0; right<s.size(); right++){
            if(freq[s[right]] > 0) count--;
            freq[s[right]]--;

            while(count == 0){
                if(right-left+1<minWindowSize){
                    minWindowSize = right-left+1;
                    startIdx = left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) count++;
                left++;
            }
        }
        return minWindowSize == INT_MAX ? "" : s.substr(startIdx,minWindowSize);
    }
};