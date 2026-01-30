class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int,vector<int>> map;

        for(int i=0; i<n; i++){
            for(int route: routes[i]){
                map[route].push_back(i);
            }
        }
        queue<int> q;
        unordered_set<int> visited;

        for(auto route: map[source]){
            q.push(route);
            visited.insert(route);
        }

        int buses = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();

                for(int stop: routes[curr]){
                    if(stop == target) return buses;

                    for(int next: map[stop]){
                        if(!visited.count(next)){
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};