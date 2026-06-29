class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        int max_time = 0;
        queue<pair<int,int>> q;
        q.push({headID,0});

        while(!q.empty()){
            auto [node,time] = q.front();
            q.pop();

            max_time = max(time,max_time);

            for(auto &a: adj[node]){
                q.push({a, time + informTime[node]});
            }
        }
        return max_time;
    }
};