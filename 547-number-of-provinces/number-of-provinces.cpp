class Solution {
public:
    void dfs(int node, vector<int> &visited,vector<vector<int>>& isConnected){
        int n = isConnected.size();
        queue<int> q;
        q.push(node);
        visited[node] =1;

        while(!q.empty()){
            auto num = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(!visited[i] && isConnected[num][i]==1){
                    q.push(i);
                    visited[i] =1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};