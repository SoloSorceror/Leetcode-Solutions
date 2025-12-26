class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        int provinces = 0;
        queue<int>q;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int j=0; j<V; j++){
                        if(!visited[j] && isConnected[node][j]==1){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};