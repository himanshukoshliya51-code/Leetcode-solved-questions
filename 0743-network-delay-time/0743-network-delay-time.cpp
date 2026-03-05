class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>> adj(n+1);

        for(auto &f : times){
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});

        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        

        while(!q.empty()){

                auto [cost,node] = q.top();
                q.pop();

                for(auto &[neighbour,weight] : adj[node]){

                    if(cost + weight < dist[neighbour]){

                        dist[neighbour] = cost + weight;

                        q.push({cost + weight,neighbour});
                    }
                }
        }
        int maxii = INT_MIN;

        for(int i=1;i<=n;i++){
            maxii = max(maxii, dist[i]);

        }

        return maxii == INT_MAX ? -1 : maxii;
    }
};