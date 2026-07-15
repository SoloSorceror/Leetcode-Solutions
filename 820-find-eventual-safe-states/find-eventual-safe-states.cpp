class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &state){
        if(state[node] == 1){
            return false;
        }
        if(state[node] == 2){
            return true;
        }

        state[node] = 1;   // Mark as visiting

        for (int child : graph[node]) {
            if (!dfs(child, graph, state))
                return false;
        }

        state[node] = 2;   // Mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(dfs(i,graph,state)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};