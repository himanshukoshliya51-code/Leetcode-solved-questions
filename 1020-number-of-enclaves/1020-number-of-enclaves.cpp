class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        if(board.empty()) return 0;

        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        // Push border O's
        for(int i = 0; i < m; i++){
            if(board[0][i] == 1)
                q.push({0,i});
            if(board[n-1][i] == 1)
                q.push({n-1,i});
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 1)
                q.push({i,0});
            if(board[i][m-1] == 1)
                q.push({i,m-1});
        }
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    cnt1++;
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int cntb= 0;

        // BFS
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if(board[r][c] != 1) continue;

            cntb++;
             board[r][c] = 0;

            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && 
                   ncol >= 0 && ncol < m && 
                   board[nrow][ncol] == 1){
                       
                    q.push({nrow, ncol});
                }
            }
        }

    return cnt1-cntb;
        
    }
};