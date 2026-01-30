class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        queue<int> q;
        vector<int> ans;
        
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &a: adj[node]){
                // indegree[a]--;
                if(--indegree[a] == 0){
                    q.push(a);
                }
            }
        }
        return ans.size()== adj.size();
    }
};