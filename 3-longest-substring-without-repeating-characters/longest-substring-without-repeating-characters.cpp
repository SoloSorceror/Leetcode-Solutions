class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
      unordered_set<char> st;
      int l = 0;
      int best = 0;

      for(int r=0; r<n;r++){
        while(st.count(s[r])){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        best = max(best, r-l+1);
      }
      return best;  
    }
};