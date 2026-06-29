class Solution {
public:
    bool dfs(int src, int dst, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = true;
        if (src == dst) {
            return true;
        }
        for (auto& s : adj[src]) {
            if (!visited[s]) {
                if (dfs(s, dst, adj, visited)) {
                    return true;
                }
            }
        };
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(source, destination, adj, visited);
    }
};