class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] != x){
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }

    void unite(int u, int v){
        int pou = findParent(u);
        int pov = findParent(v);

        if(rank[pou] > rank[pov]){
            parent[pov] = pou;
        }
        else if(rank[pov] > rank[pou]){
            parent[pou] = pov;
        }
        else{
            parent[pov] = pou;
            rank[pou]++;
        }
    }

};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto &e: edges){
            int p1 = dsu.findParent(e[0]);
            int p2 = dsu.findParent(e[1]);

            if(p1 != p2) dsu.unite(p1,p2);
        }
        return dsu.findParent(source) == dsu.findParent(destination);
    }
};