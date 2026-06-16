class Solution {
private:
    string remove(string &s){
        if(s.length()<1) return s;
        else s.pop_back();
        return s;
    }
public:
    string processStr(string s) {
        string result = "";
        for(char c: s){
            if(c=='#'){
                result = result+result;
            }
            else if(c=='*'){
                remove(result);
            }
            else if(c=='%'){
                reverse(result.begin(),result.end());
            }
            else result += c;
        }
        return result;
    }
};