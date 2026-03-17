class Solution {
public:

int findParent(int node , vector<int>& parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node] = findParent(parent[node] , parent);
}
void Union(int u , int v , vector<int>& parent , vector<int>& rank){
    int pu = findParent(u,parent);
    int pv = findParent(v,parent);

    if(pu == pv){
        return;
    }
    else if ( rank[pu]<rank[pv] ){
        parent[pu] = pv;
    }
    else if (rank[pu]>rank[pv]){
        parent[pv] = pu;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }

}
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        int n  = maxRow + maxCol + 2;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        unordered_map<int,int>stoneNodes;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;

            Union(nodeRow,nodeCol,parent,rank);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt = 0;
        for(auto it : stoneNodes){
           if(findParent(it.first,parent)==it.first ){
            cnt++;
           }
        }

        return stones.size()-cnt;


        
    }
};