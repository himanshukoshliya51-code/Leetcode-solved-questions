class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.empty()) return;

        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        // Push border O's
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O')
                q.push({0,i});
            if(board[n-1][i] == 'O')
                q.push({n-1,i});
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                q.push({i,0});
            if(board[i][m-1] == 'O')
                q.push({i,m-1});
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        // BFS
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if(board[r][c] != 'O') continue;

            board[r][c] = '#';

            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && 
                   ncol >= 0 && ncol < m && 
                   board[nrow][ncol] == 'O'){
                       
                    q.push({nrow, ncol});
                }
            }
        }

        // Final conversion
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};