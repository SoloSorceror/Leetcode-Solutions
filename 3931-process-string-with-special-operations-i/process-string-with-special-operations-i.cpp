class Solution {
public:
    string processStr(string s) {
        string result;
        result.reserve(s.length());
        for(char c: s){
            if(c=='#'){
                result += result;
            }
            else if(c=='*'){
               if(!result.empty()) result.pop_back();
            }
            else if(c=='%'){
                reverse(result.begin(),result.end());
            }
            else result += c;
        }
        return result;
    }
};