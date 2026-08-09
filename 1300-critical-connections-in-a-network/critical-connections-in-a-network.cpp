class Solution {
public:
    vector<int> visited;
    vector<int> tin;
    vector<int> low;
    vector<vector<int>> bridges;
    int timer = 0;

    void dfs(int curr, int parent, vector<vector<int>>& graph) {
        visited[curr] = 1;
        tin[curr] = low[curr] = timer++;

        for (int next : graph[curr]) {

            // Ignore the edge used to reach curr
            if (next == parent)
                continue;

            if (!visited[next]) {
                dfs(next, curr, graph);

                low[curr] = min(low[curr], low[next]);

                // No back-edge from next's subtree to curr or above
                if (low[next] > tin[curr]) {
                    bridges.push_back({curr, next});
                }
            }
            else {
                // Back edge
                low[curr] = min(low[curr], tin[next]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {
        visited.assign(n, 0);
        tin.assign(n, 0);
        low.assign(n, 0);

        bridges.clear();
        timer = 0;

        vector<vector<int>> graph(n);

        for (auto& c : connections) {
            int u = c[0];
            int v = c[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, graph);
            }
        }

        return bridges;
    }
};