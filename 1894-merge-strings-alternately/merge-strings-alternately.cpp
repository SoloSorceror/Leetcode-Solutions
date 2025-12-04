class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans;
        int i = 0;

        while(i< a.size() || i < b.size()){
            if(i<a.size()) ans+= a[i];
            if(i<b.size()) ans+= b[i];
            i++;
        }
        return ans;
    }
};