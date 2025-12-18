class Solution {
public:
    bool dfs(int start, int c, vector<vector<int>>& graph,
             vector<int>& colour) {
        colour[start] = c;

        for (auto& a : graph[start]) {
            if (colour[a] == -1) {
                if (!dfs(a, !c, graph, colour)) {
                    return false;
                }
            } else if (colour[a] == c) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);

        for (int i = 0; i < n; i++) {
            if (colour[i] == -1) {
                if (!dfs(i, 0, graph, colour)) {
                    return false;
                }
            }
        }
        return true;
    }
};