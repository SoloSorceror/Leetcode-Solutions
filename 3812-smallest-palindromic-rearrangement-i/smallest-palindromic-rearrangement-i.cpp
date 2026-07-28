class Solution {
public:
    string smallestPalindrome(string str) {
        if(str.size() == 1) return str;

        vector<int> mp(26,0);
        for(auto &s: str){
            mp[s-'a']++;
        }
        string ans = str;
        int left = 0, right = str.size()-1;
        bool first = false;
        string val = "";

        for(int i=0; i<26; i++){
            int count = mp[i];
            if(count==0) continue;

            if(count == 1){
                val = 'a' + i;
                continue;
            }
            int curr = count;
            while(count>0){
                if(curr % 2 != 0){
                    val = 'a' + i;
                    count--;
                    curr = 2;
                    continue;
                }
                ans[left++] = 'a' + i;
                count--;
                if(count>0){
                    ans[right--] = 'a' + i;
                    count--;
                }
            }
        }
        string buildAns = "";

        if(val != ""){
            int half = ans.size()/2;
            buildAns += ans.substr(0,half);
            buildAns += val;
            buildAns += ans.substr(half+1,ans.size());
            return buildAns;
        }
        return ans;
    }
};