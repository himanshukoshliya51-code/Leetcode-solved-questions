class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        set<pair<int,int>> mpp;   // changed here
        queue<pair<int,int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        // Store all '1' cells
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    mpp.insert({i, j});
                }
            }
        }

        if(mpp.empty()) return 0;

        auto it = mpp.begin();
        q.push(*it);
        mpp.erase(*it);   // remove from set

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == '1' &&
                   mpp.count({nrow, ncol})) {

                    q.push({nrow, ncol});
                    mpp.erase({nrow, ncol});   // erase directly
                }
            }

            // When one island BFS finishes
            if(q.empty() && !mpp.empty()){
                cnt++;
                auto it = mpp.begin();
                q.push(*it);
                mpp.erase(*it);
            }
        }

        return cnt + 1;  // +1 for first island
    }
};