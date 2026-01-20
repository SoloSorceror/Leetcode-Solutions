class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){
            for(int v: graph[i]){
                revGraph[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safe;

        // Kahn's ALgorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(int prev: revGraph[node]){
                if(--indegree[prev]==0){
                    q.push(prev);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};