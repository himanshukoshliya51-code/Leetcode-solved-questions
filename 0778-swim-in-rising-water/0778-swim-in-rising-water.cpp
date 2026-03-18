class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
    
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<>
    > pq;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    pq.push({grid[0][0], {0, 0}});
    
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    while(!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int time = it.first;
        int r = it.second.first;
        int c = it.second.second;
        
        if(r == n-1 && c == n-1) return time;
        
        if(vis[r][c]) continue;
        vis[r][c] = 1;
        
        for(auto d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            
            if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]) {
                int newTime = max(time, grid[nr][nc]);
                pq.push({newTime, {nr, nc}});
            }
        }
    }
    
    return -1;
    }
};