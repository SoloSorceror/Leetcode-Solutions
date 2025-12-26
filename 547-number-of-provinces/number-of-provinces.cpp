class Solution {
public:
    void dfs(int src,int V, vector<bool> &visited,vector<vector<int>>& isConnected){
        visited[src] = true;

        for(int i=0; i<V; i++){
            if(!visited[i] && isConnected[src][i] == 1){
                dfs(i,V,visited,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V,false);
        int province = 0;
        for(int i =0; i<V; i++){
            if(!visited[i]){
                dfs(i,V, visited,isConnected);
                province++;
            }
        }
        return province;
    }
};