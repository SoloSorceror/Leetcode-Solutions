class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,-1);
        
        for(int start = 0; start<n; start++){
            if(colour[start]== -1){
                queue<int> q;
                q.push(start);
                colour[start] =0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto &a: graph[node]){
                        if(colour[a] == -1){
                            colour[a] = !colour[node];
                            q.push(a);
                        }else if(colour[a] == colour[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;

    }
};