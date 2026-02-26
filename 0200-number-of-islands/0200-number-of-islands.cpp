class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == '1') {
                    
                    count++;   // New island found
                    
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';   // mark visited
                    
                    while(!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        
                        int r = node.first;
                        int c = node.second;
                        
                        for(int k = 0; k < 4; k++) {
                            int nrow = r + delRow[k];
                            int ncol = c + delCol[k];
                            
                            if(nrow >= 0 && nrow < n &&
                               ncol >= 0 && ncol < m &&
                               grid[nrow][ncol] == '1') {
                                
                                grid[nrow][ncol] = '0'; // mark visited
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};