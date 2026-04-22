class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        int count = t.size();
        int startIdx = 0;
        int minWindow = INT_MAX;
        int left = 0;

        for(char c: t) freq[c]++;

        for(int right=0; right<s.size(); right++){
            if(freq[s[right]]>0) count--;
            freq[s[right]]--;

            while(count==0 ){
                if(right-left+1<minWindow){
                    startIdx = left;
                    minWindow = right-left+1;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0) count++;
                left++;
            }
        }
        return minWindow==INT_MAX ? "": s.substr(startIdx,minWindow);
    }
};