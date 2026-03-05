class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto [cost,node] = pq.top();
            pq.pop();

            for(auto &[neigh,weight] : adj[node]){

                long long newDist = cost + weight;

                if(newDist < dist[neigh]){

                    dist[neigh] = newDist;

                    ways[neigh] = ways[node];

                    pq.push({newDist, neigh});
                }

                else if(newDist == dist[neigh]){

                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};