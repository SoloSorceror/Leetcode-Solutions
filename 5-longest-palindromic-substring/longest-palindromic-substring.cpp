class Solution {
public:
string expandAround(const string &s, int L, int R) {
    int n = s.size();
    while (L >= 0 && R < n && s[L] == s[R]) {
        --L; ++R;
    }
    // when loop exits, s[L+1..R-1] is palindrome
    return s.substr(L + 1, R - L - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    string best = s.substr(0,1);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        // odd length
        string p1 = expandAround(s, i, i);
        if (p1.size() > best.size()) best = p1;
        // even length
        string p2 = expandAround(s, i, i+1);
        if (p2.size() > best.size()) best = p2;
    }
    return best;
}
};