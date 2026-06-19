class Solution {
public:
    int reverse(int x) {
        bool flag = x<0? true: false;
        string s = to_string(x);
        std::reverse(s.begin(),s.end());
        if(stoll(s) > INT_MAX) return 0;
        return flag? -stoi(s): stoi(s); 
    }
};