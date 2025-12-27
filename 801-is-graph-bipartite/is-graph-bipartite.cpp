class Solution {
public:
    bool dfs(int src, int c,vector<vector<int>>& graph,vector<int> &colors){
        colors[src] = c;

        for(auto &a: graph[src]){
            if(colors[a] == -1){
                if(!dfs(a,!c,graph,colors)){
                    return false;
                }
            }else if(colors[a] == c){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colors(V,-1);

        for(int i=0; i<V; i++){
            if(colors[i] == -1){
                if(!dfs(i,0,graph,colors)){
                    return false;
                }
            }
        }
        return true;   
    }
};