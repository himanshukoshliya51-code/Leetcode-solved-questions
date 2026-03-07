class Solution {
public:

    int findParent(int node, vector<int>& parent){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void Union(int u, int v, vector<int>& parent, vector<int>& rank){
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if(pu == pv) return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;

        vector<int> parent(n);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++)
            parent[i] = i;

        for(auto &it : connections){
            Union(it[0], it[1], parent, rank);
        }

        int components = 0;

        for(int i=0;i<n;i++){
            if(parent[i] == i)
                components++;
        }

        return components - 1;
    }
};