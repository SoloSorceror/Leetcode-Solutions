class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> stopToRoutes;
        int n = routes.size();

        // Build stop -> routes map
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q; // store route index
        unordered_set<int> visitedRoutes;

        // Start with all routes that include source
        for (int route : stopToRoutes[source]) {
            q.push(route);
            visitedRoutes.insert(route);
        }

        int buses = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int currRoute = q.front();
                q.pop();

                // check all stops in this route
                for (int stop : routes[currRoute]) {
                    if (stop == target)
                        return buses;
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoutes.count(nextRoute)) {
                            visitedRoutes.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};