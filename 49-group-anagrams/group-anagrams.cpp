class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto& s : strs) {
            vector<int> count(26,0);
            for(auto &x: s){
                count[x - 'a']++;
            }
            string key = "";
            for(int a: count){
                key += "," + to_string(a);
            }
            map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &a: map){
            ans.push_back(a.second);
        }
        return ans;
    }
};