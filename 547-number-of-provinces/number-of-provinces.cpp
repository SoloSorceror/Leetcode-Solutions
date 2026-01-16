class Solution {
public:
    void dfs(int node, vector<int> &visited,vector<vector<int>>& isConnected){
        visited[node] = 1;
        int n = isConnected.size();
        for(int i=0; i<n; i++){
            if(!visited[i] && isConnected[node][i] == 1){
                dfs(i, visited, isConnected);
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