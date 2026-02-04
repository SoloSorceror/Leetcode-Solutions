class Solution {
public:
    string minWindow(string s, string t) {

        // Edge case: if t is bigger than s, impossible
        if (t.size() > s.size()) return "";

        // Frequency map for characters in t
        vector<int> need(256, 0);

        // Fill need[] with frequency of characters in t
        for (char c : t) {
            need[c]++;
        }

        // window[] will store frequency of characters in current window
        vector<int> window(256, 0);

        int required = 0;   // number of unique characters in t
        for (int i = 0; i < 256; i++) {
            if (need[i] > 0) required++;
        }

        int formed = 0;     // how many characters currently meet their required count

        int left = 0;       // left pointer of window
        int right = 0;      // right pointer of window

        int minLen = INT_MAX;  // length of best (minimum) window found
        int start = 0;         // starting index of best window

        // Start expanding the window
        while (right < s.size()) {

            char c = s[right];
            window[c]++;   // include current character into window

            // If this character is required and its frequency just matched the need
            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            // Try shrinking window when it becomes valid
            while (formed == required) {

                // Update answer if this window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the leftmost character from window
                char removeChar = s[left];
                window[removeChar]--;

                // If removing breaks the required frequency, window is no longer valid
                if (need[removeChar] > 0 && window[removeChar] < need[removeChar]) {
                    formed--;
                }

                left++; // shrink from left
            }

            right++; // expand window from right
        }

        // If we never found a valid window
        if (minLen == INT_MAX) return "";

        // Return the smallest window substring
        return s.substr(start, minLen);
    }
};
