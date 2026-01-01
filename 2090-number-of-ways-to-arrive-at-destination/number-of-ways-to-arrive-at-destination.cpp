class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            // 🔑 critical Dijkstra guard
            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                long long edw = it.second;

                if (dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dis + edw == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
