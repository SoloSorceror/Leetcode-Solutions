class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int count = 0;
        int sz = words.size();

        if(sz==1) return true;

        for (auto& w : order) {
            mp[w] = count++;
        }


        for (int i = 1; i < sz; i++) {
            string str1 = words[i-1];
            string str2 = words[i];

            int minLen = min(str1.size(), str2.size());

            if (str1.substr(0, minLen) == str2.substr(0, minLen) && str1.size() > str2.size()) {
                return false;
            }

            for(int itr = 0; itr<minLen; itr++){
                if(str1[itr] != str2[itr]){
                    if(mp[str1[itr]] > mp[str2[itr]]){
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};