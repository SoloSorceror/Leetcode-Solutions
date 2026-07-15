class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, unordered_set<int> &keys){
        if(keys.find(node) != keys.end()) return;
        keys.insert(node);
        
        for(auto& n: rooms[node]){
            dfs(n,rooms,keys);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        dfs(0,rooms,keys);
        return keys.size() == rooms.size();
    }
};