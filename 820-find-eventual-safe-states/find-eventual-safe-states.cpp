class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited, vector<int>& path,
             vector<int>& safe) {

        visited[node] = 1;
        path[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, path, safe))
                    return true;
            }
            else if (path[nbr]) {
                return true; // cycle
            }
        }

        path[node] = 0;
        safe[node] = 1; // no cycle from here
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0), path(V, 0), safe(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, path, safe);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};
