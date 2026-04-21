class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        for(char c: t) freq[c]++;

        int left = 0, count = t.size();
        int minLen = INT_MAX, startIdx = 0;

        for(int right =0; right<s.size(); right++){
            if(freq[s[right]] > 0) count--;
            freq[s[right]]--;

            while(count == 0){
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    startIdx = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0) count++;
                left++;
            }
        }
        return minLen == INT_MAX? "": s.substr(startIdx,minLen);
    }
};