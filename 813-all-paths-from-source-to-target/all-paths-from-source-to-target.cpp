class Solution {
public:

    void dfs(int src, int dst, vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> &path){
        path.push_back(src);
        if(src == dst){
            ans.push_back(path);
        }

        for(auto &g: graph[src]){
            dfs(g,dst,graph,ans,path);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;

        vector<vector<int>> ans;
        dfs(0,n-1,graph,ans,path);
        return ans;
    }
};