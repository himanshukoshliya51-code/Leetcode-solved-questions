class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int,int>> q;
        q.push({src,0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        int stops = 0;

        while(!q.empty() && stops <= k){

            int size = q.size();

            while(size--){

                auto [node,cost] = q.front();
                q.pop();

                for(auto &[neighbour,weight] : adj[node]){

                    if(cost + weight < dist[neighbour]){

                        dist[neighbour] = cost + weight;

                        q.push({neighbour, cost + weight});
                    }
                }
            }

            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};