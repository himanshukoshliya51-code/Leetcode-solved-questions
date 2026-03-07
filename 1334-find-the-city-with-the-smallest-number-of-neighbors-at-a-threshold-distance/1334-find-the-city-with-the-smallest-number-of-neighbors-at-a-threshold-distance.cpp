class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
         for(int i = 0; i < n; i++){
        adj[i][i] = 0;
    }

    // fill matrix using edges
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(adj[i][j]<=distanceThreshold){
                cnt++;

            }
        }
        ans[i]=cnt;
    }
    int mini = 0;
    for(int i=1;i<n;i++){
        if(ans[i]<ans[mini]){
            mini = i;
        }
        else if(ans[i]==ans[mini]){
            mini = max(mini,i);

        }

    }
        return mini;
    }
};